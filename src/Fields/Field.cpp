//
// Created by adrwal on 11/3/24.
//

#include "Field.h"

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

std::vector<PlayerDecisionOutputs> Field::getFieldDecisions(Player* player) const
{
    std::vector<PlayerDecisionOutputs> baseDecisions = {PlayerDecisionOutputs::NO_DECISION};

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
    // TODO
    return false;
}

bool Field::canUnmortgageAnyField(Player* player) const
{
    // TODO
    return false;
}

bool Field::canSellAnyHouse(Player* player) const
{
    // TODO
    return false;
}
