#include <libultraship/bridge.h>
#include "port/UI/cvar_prefixes.h"
#include "enums.h"
#include "functions.h"

// Snapshot the option when this Game Over actually starts.
// Changing the checkbox while it is already playing must not change
// the timing/music of the Game Over currently in progress.
static bool sShortGameOverActive = false;

extern "C" int port_getGameOverSignMusicTrack(void) {
    // MAP_83 is the full Gruntilda Game Over machine-room cutscene.
    // Its cutscene logic eventually spawns the normal Game Over sign too,
    // so never let that sign select the restored short theme.
    sShortGameOverActive =
        (gsworld_getMap() != MAP_83_CS_GAME_OVER_MACHINE_ROOM) &&
        (CVarGetInteger(CVAR_ENHANCEMENT("Restorations.ShortGameOverTheme"), 0) != 0);

    return sShortGameOverActive
               ? COMUSIC_5C_BETA_GAME_OVER
               : COMUSIC_31_GAME_OVER;
}

extern "C" float port_getShortGameOverFadeDelay(void) {
    // The unused short Game Over reference ends at 3.833333333 s.
    // The existing Game Over cleanup uses a 200 ms music fade, so
    // begin the fade at the final phrase onset, 3.0 s, when this restoration is enabled.
    return sShortGameOverActive ? 3.0f : 5.0f;
}

extern "C" float port_getShortGameOverScreenFadeDelay(void) {
    // Use the option state captured when the current Game Over began.
    // This prevents unchecking the option mid-Game-Over from switching
    // the active short Game Over back to the stock 5-second delay.
    return sShortGameOverActive ? 3.0f : 5.0f;
}
