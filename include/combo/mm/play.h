#ifndef MM_PLAY_H
#define MM_PLAY_H

#include <combo/game_state.h>

typedef struct PACKED ALIGNED(4)
{
    GameState    gs;
    u16          sceneId;
    char         unk_000a6[0x1624a];
    char         textBuffer[4]; /* Real size unknown */
    char         unk_162f4[0x2f64];
}
GameState_Play;

_Static_assert(sizeof(GameState_Play) == 0x19258, "MM GameState_Play size is wrong");

#endif