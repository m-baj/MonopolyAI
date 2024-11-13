//
// Created by Maksymilian Baj on 08.11.2024.
//

#include "OwnableField.h"
#include "Board.h"

std::optional<Player*> OwnableField::getOwner() const
{
    for(const auto& player : this->board.getPlayers())
    {
        for (const auto& ownableField : player->getOwnedFields())
        {
            if (ownableField.get() == this)
            {
                return player.get();
            }
        }
    }
    return std::nullopt;
}