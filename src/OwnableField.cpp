//
// Created by Maksymilian Baj on 08.11.2024.
//

#include "OwnableField.h"
#include "Board.h"

std::optional<Player*> OwnableField::getOwner() const
{
    if (owner == nullptr)
    {
        return std::nullopt;
    }
    return owner;
}

void OwnableField::setOwner(Player *player) {
    owner = player;
}
