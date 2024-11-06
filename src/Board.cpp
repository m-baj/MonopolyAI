//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "CardField.h"

Board::Board()
{
}

void Board::push_field(std::shared_ptr<Field> field)
{
    this->fields.push_back(field);
}

void Board::addPlayer(std::unique_ptr<Player> player)
{
    players.push_back(std::move(player));
}

Player* Board::getCurrentPlayer() const
{
    return this->players[this->currentPlayerIndex].get();
}


int Board::rollDice() const
{
    return (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
}

void Board::movePlayer(int steps)
{
    auto currentPlayer = this->getCurrentPlayer();
    if(this->willMoveCrossStart(currentPlayer, steps))
    {
        // TODO: Implement passing start
    }
    currentPlayer->setPositionIdx(this->getNewPosition(currentPlayer, steps));
    this->fields[currentPlayer->getPositionIdx()]->onPlayerEnter(currentPlayer);
}

bool Board::willMoveCrossStart(Player* player, int steps) const
{
    return this->getNewPosition(player, steps) < player->getPositionIdx();
}

int Board::getNewPosition(Player* player, int steps) const
{
    int fieldsCount = this->fields.size();
    int currentPosition = player->getPositionIdx();
    int newPosition = (currentPosition + steps) % fieldsCount;
    return newPosition;
}
