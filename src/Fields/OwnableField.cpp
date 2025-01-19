//
// Created by Maksymilian Baj on 08.11.2024.
//

#include "OwnableField.h"

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

bool OwnableField::canBuy(Player* player) const
{
    if (owner)
    {
        return false;
    }
    if (player->getMoney() > baseBuyPrice)
    {
        return true;
    }
}

int OwnableField::getBaseBuyPrice() const
{
    return baseBuyPrice;
}

std::vector<PlayerDecisionOutputs> OwnableField::getFieldDecisions(Player* player) const
{
    auto decisions = Field::getFieldDecisions(player);
    if (canBuy(player))
    {
        decisions.push_back(PlayerDecisionOutputs::BUY_FIELD);
    }
    return decisions;
}
