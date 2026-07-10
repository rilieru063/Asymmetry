#include "Reset.h"

void Reset::RESET()
{
    auto players = FindGameObjects<Player>();
    auto keys = FindGameObjects<Key>();

    for (auto player : players)
    {
        player->Reset();
    }
    for (auto key : keys) {
        key->Reset();
    }
}