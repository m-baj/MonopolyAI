//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "BoardExceptions.h"
#include "CardField.h"

Board::Board()
{
}

const std::vector<std::unique_ptr<Player>>& Board::getPlayers() const
{
    return this->players;
}

void Board::pushField(std::shared_ptr<Field> field)
{
    this->fields.push_back(field);
}

void Board::pushPlayer(std::unique_ptr<Player> player)
{
    players.push_back(std::move(player));
}

void Board::setRoundState(RoundState state)
{
    this->roundState = state;
}

RoundState Board::getRoundState() const
{
    return this->roundState;
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
    if (this->roundState != RoundState::ROLL_DICE)
    {
        throw InvalidMoveException("Broken rules! Player wanted to move with round state not being ROLL_DICE");
    }

    auto currentPlayer = this->getCurrentPlayer();
    if(this->willMoveCrossStart(currentPlayer, steps))
    {
        // TODO: Implement passing start
    }
    currentPlayer->setPositionIdx(this->getNewPosition(currentPlayer, steps));
    this->setRoundState(RoundState::HANDLE_FIELD);
    this->fields[currentPlayer->getPositionIdx()]->onPlayerEnter(currentPlayer);
}

void Board::notifyPlayer(Player *player, const GameEvent &event) {
    player->handleEvent(event);
}


void Board::setCurrentPlayerIndex(int index)
{
    this->currentPlayerIndex = index;
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

const std::vector<std::shared_ptr<Field>>& Board::getFields() const
{
    return this->fields;
}