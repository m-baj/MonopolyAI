//
// Created by adrwal on 11/3/24.
//

#include "Property.h"
#include "Board.h"

void Property::onPlayerEnter(Player *player) {
    std::optional<Player *> owner = getOwner();
    if (owner.has_value())
        handleOwnedProperty(player, owner.value());
    else
        handleUnownedProperty(player);
}

void Property::handleOwnedProperty(Player *player, Player *owner) {
    if (owner != player && !isMortgaged)
    {
        player->payMoneyTo(owner, calculateRentPrice());
    }
    else if (owner == player && !isMortgaged)
    {
        // TODO: Implement possibility to upgrade property
    }
    else if (owner == player)
    {
        // TODO: Implement handling of mortgaged property
    }
}

void Property::handleUnownedProperty(Player *player)
{
    // TODO: Implement possibility to buy property
}

int Property::calculateRentPrice() const
{
    return baseRentPrice;
}

std::optional<Player*> Property::getOwner() const
{
    for (const auto& player : board.getPlayers())
    {
        for (const auto& property : player->getProperties())
        {
            if (property.get() == this)
            {
                return player.get();
            }
        }
    }
    return std::nullopt;
}
