#include "../include/BPS/main_include.hpp"
#include "../include/actor.hpp"

#include "../assets/backgrounds/WorldMap.h"
#include "../assets/backgrounds/WorldMap.c"

OBJ_ATTR _objBuffer[128];
u32 _oamIndex;

void ResetOAM()
{
    memset(_objBuffer, 0, sizeof(_objBuffer));
    _oamIndex = 0;
}

void SetBackground()
{
    memcpy(BACKGROUND_PALETTE_MEMORY, WorldMapPal, WorldMapPalLen);
    memcpy(&tile_mem[0][0], WorldMapTiles, WorldMapTilesLen);
    memcpy(&screen_entry_memory[30][0], WorldMapMap, WorldMapMapLen);
}

int offset = 0;

int main()
{
    irqInit();
    irqEnable(IRQ_VBLANK);
    
    SetBackground();

    BG0_CONTROL_REGISTER = BG_CHARBLOCK_BASE(0) | BG_SCREENBLOCK_BASE(30) | BG_4BPP | BG_REGULAR_32x32;
    DISPLAY_REGISTER = SCRN_LAYER_OBJ | OBJ_1D_MAPPING | DISPLAY_MODE0 | SCRN_LAYER_BG0;
    

    OAMInit(_objBuffer, 128);
    
    InitPlayer();

    while(1)
    {
        VBlankIntrWait();
        ResetOAM();

        // offset -= 1;
        // BG0_HOR_OFFSET = offset;

        UpdatePlayer();

        OAMCopy(OAM_REGISTER, _objBuffer, _oamIndex);
    }

    return 0;
}
