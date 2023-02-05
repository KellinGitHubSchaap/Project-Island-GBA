#include "../include/actor.hpp"

#include "../source/BPS/key_inputs.cpp"

#include "../assets/player/player.h"
#include "../assets/player/player.c"

Vector2Int position = {0, 0};
Sprite* player;

void InitPlayer()
{
    player = new Sprite(0, playerTiles, playerTilesLen, 0, playerPal, playerPalLen);
}

void UpdatePlayer()
{
    ScanKeys();

    if(GetKey(KEY_RIGHT))
    {
        position.x += 1;
    }
    else if(GetKey(KEY_LEFT))
    {
        position.x -= 1;
    }

    if(GetKey(KEY_UP))
    {
        position.y -= 1;
    }
    else if(GetKey(KEY_DOWN))
    {
        position.y += 1;
    }

    player->SetPosition(position.x, position.y);
    player->Render();
}