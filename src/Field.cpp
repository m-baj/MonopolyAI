//
// Created by adrwal on 11/3/24.
//

#include "Field.h"
#include "Board.h"

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
