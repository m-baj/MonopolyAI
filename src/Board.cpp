//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "Exceptions/BoardExceptions.h"
#include "Fields/CardField.h"
#include "Player.h"

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

Field* Board::getSteppedOnField() const
{
    return this->fields[this->getCurrentPlayer()->getPositionIdx()].get();
}

void Board::setRollDiceSeed(int seed)
{
    rollDiceSeed = seed;
}

Player* Board::getCurrentPlayer() const
{
    return this->players[this->currentPlayerIndex].get();
}


int Board::rollDice() const
{
    if (rollDiceSeed != 0)
    {
        return rollDiceSeed;
    }
    return (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
}

void Board::movePlayer(int steps)
{
    auto currentPlayer = this->getCurrentPlayer();
    if(this->willMoveCrossStart(currentPlayer, steps))
    {
        currentPlayer->addMoney(CROSSING_START_BONUS);
    }
    currentPlayer->setPositionIdx(this->getNewPosition(currentPlayer, steps));
    this->fields[currentPlayer->getPositionIdx()]->onPlayerEnter(currentPlayer);
}

void Board::nextPlayer()
{
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
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
void Board::pushChanceCard(std::unique_ptr<Card> card) {
    this->chanceCards.push_back(std::move(card));
}

void Board::pushCommunityChestCard(std::unique_ptr<Card> card) {
    this->communityChestCards.push_back(std::move(card));
}
