//
// Created by adrwal on 11/3/24.
//
#include <algorithm>
#include "Field.h"
#include <iostream>
#include <algorithm>
#include <ranges>

#include "Property.h"
#include "../Board.h"
#include "../Constants.h"
#include "../Player.h"

std::string Field::getName() const
{
    return this->name;
}

std::vector<std::optional<Player*>> Field::getPlayersOnField() const
{
    std::vector<std::optional<Player*>> playersArr = {};
    auto fieldIdx = this->getFieldIdx();
    for (const auto& player : this->board.getPlayers())
    {
        if (player->getPositionIdx() == fieldIdx)
        {
            playersArr.emplace_back(player.get());
        }
    }
    return playersArr;
}

int Field::getFieldIdx() const
{
    for (int i = 0; i < this->board.getFields().size(); i++)
    {
        if (this->board.getFields()[i].get() == this)
        {
            return i;
        }
    }
    return -1;
}

const Board& Field::getBoard() const
{
    return board;
}

std::vector<PlayerDecisionOutputs> Field::getFieldDecisions(Player* player) const
{
    std::vector<PlayerDecisionOutputs> baseDecisions = {};

    if (std::ranges::find(
        player->getMadeTurnDecisions(),
        PlayerDecisionOutputs::NO_DECISION)
        != player->getMadeTurnDecisions().end())
    {
        return baseDecisions;
    }

    baseDecisions.push_back(PlayerDecisionOutputs::NO_DECISION);

    if(canMortgageAnyField(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::MORTGAGE_FIELD);
    }
    if(canUnmortgageAnyField(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::UNMORTGAGE_FIELD);
    }
    if(canSellAnyHouse(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::SELL_HOUSE);
    }

    return baseDecisions;
}

bool Field::canMortgageAnyField(Player* player) const
{
    for (const auto& property : player->getProperties())
    {
        if (!property->getIsMortgaged())
        {
            return true;
        }
    }

    return false;
}

bool Field::canUnmortgageAnyField(Player* player) const
{
    for (const auto& property : player->getProperties())
    {
        if (!property->getIsMortgaged())
            continue;

        if (static_cast<int>(property->getMortgagePrice() * UNMORTGAGE_INTEREST_MULTIPLIER) < player->getMoney())
        {
            return true;
        }
    }

    return false;
}

bool Field::canSellAnyHouse(Player* player) const
{
    for (const auto& property : player->getProperties())
    {
        if (property->getNumberOfHouses() > 0)
        {
            return true;
        }
    }

    return false;
}
