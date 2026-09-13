// BanjoDecomp: core2/code_73640.c
#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "bk_time.h"

#define _73640_MAX(s,t) ((s < t)? t: s)
#define _73640_MIN(s,t) ((s > t)? t: s)

// [port] _new funcs have varying signatures (struct7s*/struct8s*/void* returns, asset_e/item_e/s32 params).
// On N64 these were all equivalent. Use a generic function pointer type and cast in initializer.
typedef void *(*ItemPrintNewFn)(s32);

typedef struct item_print_s{
    ItemPrintNewFn unk0;
    void (*unk4)(s32, struct8s *);
    void (*unk8)(enum item_e, struct8s *, Gfx**, Mtx**, Vtx**);
    void (*unkC)(s32, struct8s *);
    s32 unk10;
    struct8s *unk14;
} ItemPrint;


s32 func_802FAD9C(enum item_e item_id);
extern s32 port_restoreUnusedXmasTreeTimerEnabled(void);

/* .data */
s16 D_803692E0[6] = {
    ASSET_89D_ZOOMBOX_SPRITE, 
    ASSET_7D9_SPRITE_NOTE, 
    ASSET_7DD_SPRITE_HEALTH, 
    ASSET_35F_MODEL_JIGGY, 
    0x360, 
    -1
};
// Lighthouse [port] This array was incorrectly sized
s16 D_803692EC[5] = {
    ASSET_580_SPRITE_RED_FEATHER, 
    ASSET_6D1_SPRITE_GOLDFEATHER, 
    ASSET_41A_SPRITE_MUMBO_TOKEN, 
    ASSET_36D_SPRITE_BLUE_EGG, 
    -1
};

#define NF(fn) (ItemPrintNewFn)(fn)
#define UF(fn) (void (*)(s32, struct8s *))(fn)
#define DF(fn) (void (*)(enum item_e, struct8s *, Gfx**, Mtx**, Vtx**))(fn)
ItemPrint D_803692F8[0x2C] = {
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 5, NULL }, //ITEM_0_HOURGLASS_TIMER
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 0, NULL }, // ITEM_1_SKULL_HOURGLASS_TIMER
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //2
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 5, NULL }, //ITEM_3_PROPELLOR_TIMER
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 5, NULL }, //ITEM_5_XMAS_TREE_TIMER
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //ITEM_6_HOURGLASS
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //ITEM_7_SKULL_HOURGLASS
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //8
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //ITEM_9_PROPELLOR
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //10
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //ITEM_B_XMAS_TREE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 1, NULL }, //ITEM_C_NOTE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 1, NULL }, //ITEM_D_EGGS
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 3, NULL }, //ITEM_14_HEALTH
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 1, NULL }, //ITEM_F_RED_FEATHER
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 1, NULL }, //ITEM_10_GOLD_FEATHER
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //17
    { NF(fxjinjoscore_new), UF(fxjinjoscore_update), DF(fxjinjoscore_draw), UF(fxjinjoscore_free),   3, NULL }, //ITEM_12_JINJOS
    { NF(fxhoneycarrierscore_new), UF(fxhoneycarrierscore_update), DF(fxhoneycarrierscore_draw), UF(fxhoneycarrierscore_free), 0, NULL }, //ITEM_13_EMPTY_HONEYCOMB
    { NF(fxhealthscore_new), UF(fxhealthscore_update), DF(fxhealthscore_draw), UF(fxhealthscore_free),  0, NULL }, //ITEM_14_HEALTH
    { NF(fxcommon1score_new), UF(fxcommon1score_update), DF(fxcommon1score_draw), UF(fxcommon1score_free), 0, NULL }, //ITEM_15_HEALTH_TOTAL
    { NF(fxlifescore_new), UF(fxlifescore_update), DF(fxlifescore_draw), UF(fxlifescore_free),    6, NULL }, //ITEM_16_LIFE
    { NF(fxairscore_new), UF(fxairscore_update), DF(fxairscore_draw), UF(fxairscore_free),     0, NULL }, //ITEM_17_AIR
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_18_GOLD_BULLIONS
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_19_ORANGE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 6, NULL }, //ITEM_1A_PLAYER_VILE_SCORE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 0, NULL }, //ITEM_1B_VILE_VILE_SCORE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 2, NULL }, //ITEM_1C_MUMBO_TOKEN
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 0, NULL }, //ITEM_1D_GRUMBLIE
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 0, NULL }, //ITEM_1E_YUMBLIE
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_1F_GREEN_PRESENT
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_20_BLUE_PRESENT
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_21_RED_PRESENT
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_22_CATERPILLAR
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }, //ITEM_23_ACORNS
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 0, NULL }, //ITEM_24_TWINKLY_SCORE
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 4, NULL }, //ITEM_25_MUMBO_TOKEN_TOTAL
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 4, NULL }, //ITEM_26_JIGGY_TOTAL
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon2score_draw), UF(fxcommon2score_free), 2, NULL }, //ITEM_27_JOKER_CARD
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon1score_draw), UF(fxcommon2score_free), 5, NULL }, //40
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon1score_draw), UF(fxcommon2score_free), 3, NULL }, //41
    { NF(fxcommon2score_new), UF(fxcommon2score_update), DF(fxcommon1score_draw), UF(fxcommon2score_free), 2, NULL }, //42
    { NF(fxcommon3score_new), UF(fxcommon3score_update), DF(fxcommon3score_draw), UF(fxcommon3score_free), 2, NULL }  //43
};

/* .bss */
s32 D_803810B0;
f32 itemPrintValues[0x2C]; //item_print_value
s32 D_80381168[0x2C]; // item_e => comusic_e
f32 D_80381218[0x2C]; //item_sfx_volume???
s32 D_803812C8[0x2C]; //comusic_e
s32 D_80381378[0x2C]; //sfx_e
void *D_80381428[10];
void *D_80381450[10];
s32 D_80381478[0X2C];

/* .code */
void itemPrint_reset(void){
    s32 i;

    for(i = 0; i < 0x2C; i++){
        
        itemPrintValues[i] = item_getCount(i);
        D_80381378[i] = 0;
        D_803812C8[i] = 0;
        D_80381168[i] = 0;
        D_80381218[i] = 0.7f; //D_80377360
        
    }
}

void func_802FA69C(void){
    s32 i;

    D_803810B0 = 1;
    for(i = 0; i< 0x2C; i++){
        D_803692F8[i].unk14 = D_803692F8[i].unk0(i);
        func_802FB104(D_803692F8[i].unk10, D_803692F8[i].unk14);
    }
    itemPrint_reset();
}

void func_802FA718(s32 arg0){
    D_803810B0 = arg0;
}


void itemPrint_update(void) {
    f32 diff;
    s32 i;
    f32 sign;

    func_802FB1CC();
    for(i = 0; i< 0x2C; i++){
        if(func_802FAD9C(i)){
            if (item_getCount(i) != (s32) (itemPrintValues[i] + 0.01)) {
                diff = (f32) item_getCount(i) - itemPrintValues[i];
                sign = (diff >= 0.0f) ? 1.0f : -1.0f;
                if (D_80381378[i] != 0) {
                    itemPrintValues[i] += sign *_73640_MIN(time_getDelta() * 6.0f, 1.0);
                } else {
                    itemPrintValues[i] += (sign * _73640_MIN(time_getDelta() * _73640_MAX(diff, 8.0f), 1.0));
                }
                if ((D_80381168[i] != 0) && ((globalTimer_getTime() & 7) == 0)) {
                    coMusicPlayer_playMusic(D_80381168[i], 32000);
                }
                if (D_80381378[i] != 0) {
                    if ((D_80381478[i] != 0) && ((s32) diff != D_80381478[i])) {
                        if (itemPrintValues[i] > 9.0f) {
                            gcsfx_playWithPitch(D_80381378[i], D_80381218[i], 0x7D00);
                             D_80381218[i] = _73640_MIN(D_80381218[i] + 0.1, 2.0);
                        }
                    }
                }
                D_80381478[i] = diff;
                func_802FB020(D_803692F8[i].unk14, 1);
                if ((i == ITEM_14_HEALTH) || (i == ITEM_17_AIR)) {
                    func_802FB020(D_803692F8[0x16].unk14, 1);
                }
                
                if (item_getCount(i) == (s32) (itemPrintValues[i] + 0.01)) {
                    do{
                        if (D_803812C8[i] != 0) { 
                            coMusicPlayer_playMusic(D_803812C8[i], 0x7D00);
                        }
                        
                        D_80381378[i] = 0;
                        D_803812C8[i] = 0;
                        D_80381168[i] = 0;
                        D_80381218[i] = 0.7f;
                        D_80381478[i] = 0;
                    }while(0);
                }
            }
        }
    }

    for(i = 0; i< 0x2C; i++){
        func_802FB15C(D_803692F8[i].unk10, D_803692F8[i].unk14);
        D_803692F8[i].unk4(i, D_803692F8[i].unk14);
    }
}


void itemPrint_draw(Gfx **gfx, Mtx **mtx, Vtx **vtx) {
    s32 i;
    if(D_803810B0 && level_get() != LEVEL_D_CUTSCENE){
        for(i = 0; i < 0x2C; i++){
            if(!func_802E4A08() || i < 6){
                if(func_802FB0D4(D_803692F8[i].unk14)){
                    D_803692F8[i].unk8(i, D_803692F8[i].unk14, gfx, mtx, vtx);
                }
            }
        }
    }
}

void func_802FAC3C(void){
    s32 i;
    for(i = 0; i< 0x2C; i++){
        func_802FB194(D_803692F8[i].unk10, D_803692F8[i].unk14);
        D_803692F8[i].unkC(i, D_803692F8[i].unk14);
    }
}


void code_73640_printItemCount(enum item_e item_id){
    if(func_802FB0D4(D_803692F8[item_id].unk14) == 2 || item_id < 6 || item_id == ITEM_17_AIR ){
        itemPrintValues[item_id] += ((f32)item_getCount(item_id) - itemPrintValues[item_id] )*0.7;
    }
    func_802FB020(D_803692F8[item_id].unk14, 1);
}

void func_802FAD64(enum item_e item_id){
    func_802FB020(D_803692F8[item_id].unk14, 3);
}

s32 func_802FAD9C(enum item_e item_id){
    return (func_802FB0D4(D_803692F8[item_id].unk14) == 2);
}

bool func_802FADD4(enum item_e item_id){
    s32 v0 = func_802FB0D4(D_803692F8[item_id].unk14);
    return (v0 == 2)||(v0 == 1);
}

s32 itemPrint_getValue(s32 item_id){
    return itemPrintValues[item_id] + 0.01;
}

void itemPrint_init(void){
    s32 i;
    BKSpriteDisplayData *sp40;
    for(i = 0; D_803692E0[i] != -1; i++){
        D_80381428[i] = assetcache_get(D_803692E0[i]);
    }
    for(i = 0; D_803692EC[i] != -1; i++){
        D_80381450[i] = codeB3A80_getSprite(D_803692EC[i], &sp40);
    }
}

void itemPrint_free(void){
    s32 i;
    for(i = 0; D_803692E0[i] != -1; i++){
        assetcache_release(D_80381428[i]);
    }
    for(i = 0; D_803692EC[i] != -1; i++){
        assetcache_release(D_80381450[i]);
    }
}

void func_802FAFAC(enum item_e item_id, enum comusic_e music_id){
    D_80381168[item_id] = music_id;
}

void func_802FAFC0(enum item_e item_id, enum comusic_e music_id){
    D_803812C8[item_id] = music_id;
}

void func_802FAFD4(enum item_e item_id, enum sfx_e sfx_id){
    D_80381378[item_id] = sfx_id;
}

bool func_802FAFE8(enum item_e item_id){
    return func_802FCD98(D_803692F8[item_id].unk14);
}
// The Christmas-tree restoration can swap between the retail hourglass
// and the dormant tree timer without resetting the challenge countdown.
static s32 sPortXmasTreeTimerRunning = FALSE;
static s32 sPortXmasTreeTimerRestored = FALSE;
static s32 sPortXmasTreeTimerSwitching = FALSE;
static s32 sPortXmasTreeTimerTargetRestored = FALSE;

// These two HUD-style transitions share ITEM_0 and timer queue 5.
// Never let both state machines own that queue at the same time.
s32 port_betaHourglassSwitching(void);
void port_betaHourglassSyncHiddenState(void);

s32 port_xmasTreeTimerSwitching(void) {
    return sPortXmasTreeTimerSwitching;
}

static enum item_e port_xmasTreeTimerItem(s32 restored) {
    return restored ? ITEM_5_XMAS_TREE_TIMER : ITEM_0_HOURGLASS_TIMER;
}

static enum item_e port_xmasTreeTimerIndicator(s32 restored) {
    return restored ? ITEM_B_XMAS_TREE : ITEM_6_HOURGLASS;
}

static void port_xmasTreeTimerSetWithoutHud(enum item_e item, s32 value) {
    item_adjustByDiffWithoutHud(item, value - item_getCount(item));
}

void port_xmasTreeTimerStart(s32 ticks) {
    enum item_e timer;
    enum item_e indicator;
    enum item_e otherTimer;
    enum item_e otherIndicator;

    sPortXmasTreeTimerRestored = port_restoreUnusedXmasTreeTimerEnabled() != 0;
    sPortXmasTreeTimerTargetRestored = sPortXmasTreeTimerRestored;
    sPortXmasTreeTimerSwitching = FALSE;
    sPortXmasTreeTimerRunning = TRUE;

    timer = port_xmasTreeTimerItem(sPortXmasTreeTimerRestored);
    indicator = port_xmasTreeTimerIndicator(sPortXmasTreeTimerRestored);
    otherTimer = port_xmasTreeTimerItem(!sPortXmasTreeTimerRestored);
    otherIndicator = port_xmasTreeTimerIndicator(!sPortXmasTreeTimerRestored);

    // Clear stale state from the unused style without opening its HUD.
    port_xmasTreeTimerSetWithoutHud(otherIndicator, 0);
    port_xmasTreeTimerSetWithoutHud(otherTimer, 0);

    item_set(timer, ticks);
    item_set(indicator, TRUE);
}

void port_xmasTreeTimerStop(void) {
    enum item_e indicator;

    if (!sPortXmasTreeTimerRunning) {
        return;
    }

    indicator = port_xmasTreeTimerIndicator(sPortXmasTreeTimerRestored);

    // Preserve the game's normal timer dismissal behavior when possible.
    // During a style switch the indicator is already hidden, so avoid
    // re-opening anything just to set it to zero again.
    if (sPortXmasTreeTimerSwitching) {
        port_xmasTreeTimerSetWithoutHud(indicator, 0);
    } else {
        item_set(indicator, FALSE);
    }

    sPortXmasTreeTimerRunning = FALSE;
    sPortXmasTreeTimerSwitching = FALSE;
}

s32 port_xmasTreeTimerEmpty(void) {
    if (!sPortXmasTreeTimerRunning) {
        return TRUE;
    }
    return item_empty(port_xmasTreeTimerItem(sPortXmasTreeTimerRestored));
}

void port_xmasTreeTimerUpdate(void) {
    s32 desired;
    s32 remaining;
    s32 diff;
    enum item_e oldTimer;
    enum item_e oldIndicator;
    enum item_e newTimer;
    enum item_e newIndicator;

    if (!sPortXmasTreeTimerRunning) {
        return;
    }

    desired = port_restoreUnusedXmasTreeTimerEnabled() != 0;

        // If the beta hourglass is already animating out/in, let it finish first.
    // The next frame observes the newest Christmas-tree checkbox state.
    if (!sPortXmasTreeTimerSwitching && port_betaHourglassSwitching()) {
        return;
    }

    if (!sPortXmasTreeTimerSwitching) {
        if (desired == sPortXmasTreeTimerRestored) {
            return;
        }

        sPortXmasTreeTimerTargetRestored = desired;
        sPortXmasTreeTimerSwitching = TRUE;

        oldTimer = port_xmasTreeTimerItem(sPortXmasTreeTimerRestored);
        oldIndicator = port_xmasTreeTimerIndicator(sPortXmasTreeTimerRestored);

        // Stop the generic timer loop from immediately re-opening this HUD.
        port_xmasTreeTimerSetWithoutHud(oldIndicator, 0);

        // A dialog raises timers by putting hidden item 0x28 at the front
        // of timer queue 5. If it is present, dismiss that spacer first.
        // Otherwise the old timer is not the queue head and cannot complete
        // its normal slide-out cleanly.
        if (func_802FADD4(0x28)) {
            func_802FAD64(0x28);
        }

        // Now request the current timer's normal slide-off animation.
        // If 0x28 was present it will leave first, then this timer becomes
        // the queue head and continues sliding out.
        func_802FAD64(oldTimer);
        return;
    }

    // If the checkbox changes again while the old HUD is leaving,
    // honor the newest setting when the replacement pops back in.
    sPortXmasTreeTimerTargetRestored = desired;
    oldTimer = port_xmasTreeTimerItem(sPortXmasTreeTimerRestored);

    if (func_802FB0D4(D_803692F8[oldTimer].unk14) != 0) {
        // The indicator is deliberately off during the slide-out, so the
        // normal timer loop is no longer decrementing this item. Keep the
        // countdown moving here with the same tick formula used by gamestate.
        if (item_getCount(oldTimer) > 0) {
            diff = (s32)(-time_getDelta() * (float)FRAMERATE * 1.1f);
            if (diff < 0) {
                item_adjustByDiffWithoutHud(oldTimer, diff);
            }
        }
        return;
    }

    // The old timer is now completely off-screen.
    remaining = item_getCount(oldTimer);
    if (remaining <= 0) {
        sPortXmasTreeTimerSwitching = FALSE;
        return;
    }

    if (sPortXmasTreeTimerTargetRestored != sPortXmasTreeTimerRestored) {
        // Move the exact remaining countdown to the selected timer.
        port_xmasTreeTimerSetWithoutHud(oldTimer, 0);
        sPortXmasTreeTimerRestored = sPortXmasTreeTimerTargetRestored;
    }

    newTimer = port_xmasTreeTimerItem(sPortXmasTreeTimerRestored);
    newIndicator = port_xmasTreeTimerIndicator(sPortXmasTreeTimerRestored);

        // If the tree is handing control back to ITEM_0, quietly apply the
    // newest beta-hourglass style while ITEM_0 is still off-screen. This
    // prevents ITEM_0 from popping in with one graphic and immediately
    // starting a second slide-out on the same frame.
    if (!sPortXmasTreeTimerRestored) {
        port_betaHourglassSyncHiddenState();
    }

    // item_set() sends the selected timer through its normal state-1 pop-in.
    item_set(newTimer, remaining);
    item_set(newIndicator, TRUE);

    sPortXmasTreeTimerSwitching = FALSE;
}
// When the beta-hourglass checkbox changes while ITEM_0 is visibly active,
// let the current HUD use the normal timer-queue slide-out first. Only after
// it is completely off-screen is the selected graphic changed and popped in.
extern s32 port_restoreBetaHourglassEnabled(void);

static s32 sPortBetaHourglassDisplayRestored = FALSE;
static s32 sPortBetaHourglassSwitching = FALSE;
static s32 sPortBetaHourglassTargetRestored = FALSE;

s32 port_betaHourglassDisplayRestored(void) {
    return sPortBetaHourglassDisplayRestored;
}

// gamestate.c uses this only to suppress ITEM_0's automatic HUD reopen.
// ITEM_6 stays TRUE so minigames still know the timer is active.
s32 port_betaHourglassSwitching(void) {
    return sPortBetaHourglassSwitching;
}

// The Christmas-tree switch calls this only while ITEM_0 is fully hidden.
// It updates the effective hourglass graphic without starting another HUD
// transition or touching the timer count / gameplay indicator.
void port_betaHourglassSyncHiddenState(void) {
    s32 desired;

    if (sPortBetaHourglassSwitching) {
        return;
    }

    desired = port_restoreBetaHourglassEnabled() != 0;
    sPortBetaHourglassDisplayRestored = desired;
    sPortBetaHourglassTargetRestored = desired;
}

void port_betaHourglassUpdate(void) {
    s32 desired;
    s32 remaining;
    s32 diff;
    s32 timerActive;

    desired = port_restoreBetaHourglassEnabled() != 0;

        // ITEM_0 and the Christmas-tree timer share the same timer queue.
    // If the tree transition owns it, do not begin/continue a second
    // hourglass-style transition on top of it.
    if (port_xmasTreeTimerSwitching()) {
        return;
    }

    if (!sPortBetaHourglassSwitching) {
        timerActive =
            item_getCount(ITEM_0_HOURGLASS_TIMER) > 0 &&
            item_getCount(ITEM_6_HOURGLASS) != 0;

        if (!timerActive) {
            // Do not change the effective graphic in the middle of some other
            // queue-driven slide-out (for example the Christmas-tree switch).
            // Once ITEM_0 is no longer in the queue, quietly sync to the option.
            if (!func_802FADD4(ITEM_0_HOURGLASS_TIMER)) {
                sPortBetaHourglassDisplayRestored = desired;
                sPortBetaHourglassTargetRestored = desired;
            }
            return;
        }

        if (desired == sPortBetaHourglassDisplayRestored) {
            return;
        }

        sPortBetaHourglassTargetRestored = desired;
        sPortBetaHourglassSwitching = TRUE;

        // IMPORTANT: keep ITEM_6_HOURGLASS TRUE. Many minigames treat that
        // indicator as "the timer is active" and fail immediately if it is 0.
        // gamestate.c suppresses only ITEM_0's normal HUD/countdown pass while
        // this transition is active; this function keeps the countdown moving.

        // A dialog raises timers by placing hidden spacer 0x28 at the front of
        // this queue. Dismiss it first so the timer itself can become the queue head.
        if (func_802FADD4(0x28)) {
            func_802FAD64(0x28);
        }

        // Use the normal timer HUD slide-down.
        func_802FAD64(ITEM_0_HOURGLASS_TIMER);
        return;
    }

    // If the checkbox changes again while the old graphic is leaving,
    // the most recent setting is what will pop back up.
    sPortBetaHourglassTargetRestored = desired;

    if (func_802FB0D4(D_803692F8[ITEM_0_HOURGLASS_TIMER].unk14) != 0) {
        // gamestate suppresses ITEM_0's normal timer pass only while this
        // HUD transition is active. Keep the real timer count moving here.
        if (item_getCount(ITEM_0_HOURGLASS_TIMER) > 0) {
            f32 dt = time_getDelta();

            // Match the stock Bottles Bonus timer-consistency special case.
            if (getGameMode() == GAME_MODE_8_BOTTLES_BONUS) {
                dt = 1.0f / 30.0f;
            }

            diff = (s32)(-dt * (float)FRAMERATE * 1.1f);
            if (diff < 0) {
                item_adjustByDiffWithoutHud(ITEM_0_HOURGLASS_TIMER, diff);
            }
        }
        return;
    }

    // The old graphic is now completely off-screen.
    remaining = item_getCount(ITEM_0_HOURGLASS_TIMER);
    if (remaining <= 0) {
        sPortBetaHourglassDisplayRestored = sPortBetaHourglassTargetRestored;
        sPortBetaHourglassSwitching = FALSE;
        return;
    }

    // Only now allow common2score to select the other graphic.
    sPortBetaHourglassDisplayRestored = sPortBetaHourglassTargetRestored;

    // Re-enter through the normal item HUD state so the replacement uses
    // the same pop-up animation as the Christmas-tree style switch.
    item_set(ITEM_0_HOURGLASS_TIMER, remaining);

    // ITEM_6 never changed, so gameplay never sees a false timer-expired state.
    sPortBetaHourglassSwitching = FALSE;
}
