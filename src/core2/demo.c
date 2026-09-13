// BanjoDecomp: core2/demo.c
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct struct_23_s{
    u16 unk0;
    s8 unk2;
    s8 unk3;
}struct23s;

typedef struct demo_input{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u8 unk4;
    u8 unk5;
}DemoInput;

typedef struct demo_file_header{
    u8 pad0[0x4];
    DemoInput inputs[];
} DemoFileHeader;



void demo_free(void);
extern void port_fpDemoRedFeatherRepairReset(void);

DemoInput D_80371EF0 = {0, 0, 0, 2, 0};


// Unused FP demo: short stick-input nudge after the third red feather.
static s32 sFpDemoThirdFeatherStickNudgeFrames = 0;

void port_fpDemoThirdFeatherStickNudgeStart(void){
    if((getGameMode() == GAME_MODE_7_ATTRACT_DEMO) &&
       (gsworld_getMap() == MAP_27_FP_FREEZEEZY_PEAK)){
        sFpDemoThirdFeatherStickNudgeFrames = 6;
    }
}
/* .bss */
DemoInput *D_803860D0; //demo_input_ptr
DemoFileHeader * D_803860D4; //demo_file_ptr
s32 D_803860D8;//current_input
s32 D_803860DC;//total_inputs
// The unused FP 0x5B recording begins with active controller data.
// Do not consume that data while the loading/scene transition is still active.
static bool sFpDemoHoldUntilLoaded = false;

/* .code */
s32 func_80349EC0(s32 arg0){
    s32 sp1C[3];

    return nodeprop_findPositionFromActorId(arg0 + 0x1CC, sp1C);
}

int demo_readInput(OSContPad* arg0, s32* arg1){
    // Normal attract demos contain neutral padding at the beginning, so
    // consuming inputs during loading is harmless for them. The unused FP
    // 0x5B recording starts immediately. Hold its input pointer at frame 0
    // until the transition is finished, and feed a neutral controller frame.
    if (sFpDemoHoldUntilLoaded) {
        if (!gctransition_done()) {
            arg0->stick_x = D_80371EF0.unk0;
            arg0->stick_y = D_80371EF0.unk1;
            arg0->button = D_80371EF0.unk2;
            *arg1 = D_80371EF0.unk4;
            return 1;
        }

        // Transition has finished. Release once and play the recording
        // from its true first input on this same gameplay tick.
        sFpDemoHoldUntilLoaded = false;
    }

    s32 idx = D_803860D8;
    int not_eof = (idx + 1) < D_803860DC;
    DemoInput *input_ptr = not_eof ? &D_803860D0[idx] : &D_80371EF0;
    if (idx < D_803860DC)
        D_803860D8 = idx + 1;
#if 0
    DemoInput *input_ptr = &D_803860D0[D_803860D8++];
    int not_eof = D_803860D8 < D_803860DC;

    if(!not_eof)
        input_ptr = &D_80371EF0;
#endif

    arg0->stick_x = input_ptr->unk0;
    arg0->stick_y = input_ptr->unk1;
    // Apply the short unused-FP-demo stick nudge after the third red feather.
    if(sFpDemoThirdFeatherStickNudgeFrames > 0){
        s32 stickY = arg0->stick_y;
        if(stickY > -45){
            stickY = -30;
        }
        arg0->stick_y = (s8)stickY;
        sFpDemoThirdFeatherStickNudgeFrames--;
    }
    arg0->button = input_ptr->unk2;
    *arg1 = input_ptr->unk4;

    return not_eof;
}

int demo_writeInput(OSContPad* arg0, s32* arg1){
    DemoInput *input_ptr = D_803860D0 + D_803860D8;
    input_ptr->unk0 = arg0->stick_x;
    input_ptr->unk1 = arg0->stick_y;
    input_ptr->unk2 = arg0->button;
    input_ptr->unk4 = *arg1;
    D_803860D8++;
    return D_803860D8 < D_803860DC;
}

void func_80349FB0(DemoInput *input_ptr, u32 size, int arg2){
    D_803860D0 = input_ptr;
    D_803860DC = size/sizeof(DemoInput);
    D_803860D8 = 0;
    if(input_ptr);

    func_8030AFD8(0);
    func_80321854();
    debugScoreStates();
    clearScoreStates();
    func_803216D0(gsworld_getMap());
    func_8030AFA0(gsworld_getMap());
    volatileFlag_set(VOLATILE_FLAG_C4_WOZZA_HIDE_IN_SNS_PARADE, 1);
    func_8024F224();
    rand_reset();
    globalTimer_reset();
}//*/

/* returns offset of current input */
u32 func_8034A054(void){
    return D_803860D8*sizeof(DemoInput);
}


void demo_load(enum map_e map, s32 demo_id){
    sFpDemoThirdFeatherStickNudgeFrames = 0;
    if(D_803860D4)
        demo_free();
    // All other demos keep their exact stock timing/input behavior.
    sFpDemoHoldUntilLoaded =
        (map == MAP_27_FP_FREEZEEZY_PEAK) && (demo_id == 0x5B);
    port_fpDemoRedFeatherRepairReset();

    D_803860D4 = assetcache_get(0x504 + map_getLevel(map) + demo_id*0xD);
    func_80349FB0(D_803860D4->inputs, func_8033B678() - sizeof(DemoFileHeader), 0);
}

void demo_free(void){
    if(D_803860D4){
        assetcache_release(D_803860D4);
        D_803860D4 = NULL;
    }
}
