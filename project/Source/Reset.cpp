#include "Reset.h"

void Reset::RESET()
{
    auto players = FindGameObjects<Player>();

    for (auto player : players)
    {
        player->Reset();
    }
}