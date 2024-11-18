//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "BoardExceptions.h"
#include "CardField.h"
#include "Player.h"

const int CROSSING_START_BONUS = 200;

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

// void Board::setRoundState(RoundState state)
// {
//     this->roundState = state;
// }

// void Board::setPlayedGame(Game *game) {
//     playedGame = game;
// }
//
// RoundState Board::getRoundState() const
// {
//     return this->roundState;
// }

Field* Board::getSteppedOnField() const
{
    return this->fields[this->getCurrentPlayer()->getPositionIdx()].get();
}

// Game* Board::getPlayedGame() const {
//     return playedGame;
// }

// std::unique_ptr<ChoiceSelection> Board::createChoiceSelection(const Decision& decision, const std::string& label)
// {
//     if()
// }

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
    // if (this->roundState != RoundState::WAIT_FOR_ROLL_DICE)
    // {
    //     throw InvalidMoveException("Broken rules! Player wanted to move with round state not being ROLL_DICE");
    // }

    auto currentPlayer = this->getCurrentPlayer();
    if(this->willMoveCrossStart(currentPlayer, steps))
    {
        currentPlayer->addMoney(CROSSING_START_BONUS);
    }
    currentPlayer->setPositionIdx(this->getNewPosition(currentPlayer, steps));
    // this->setRoundState(RoundState::HANDLE_FIELD);
    this->fields[currentPlayer->getPositionIdx()]->onPlayerEnter(currentPlayer);
    // this->setRoundState(RoundState::ACCEPT_PLAYER_DECISIONS);
}

void Board::nextPlayer()
{
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    // this->setRoundState(RoundState::WAIT_FOR_ROLL_DICE);
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