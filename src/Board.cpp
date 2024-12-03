//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "Exceptions/BoardExceptions.h"
#include "Fields/CardField.h"
#include "Player.h"

Board::Board() {
}

const std::vector<std::unique_ptr<Player>>& Board::getPlayers() const {
    return this->players_;
}

void Board::pushField(std::shared_ptr<Field> field) {
    this->fields_.push_back(field);
}

void Board::pushPlayer(std::unique_ptr<Player> player) {
    players_.push_back(std::move(player));
}

Field* Board::getSteppedOnField() const {
    return this->fields_[this->getCurrentPlayer()->getPositionIdx()].get();
}

Player* Board::getCurrentPlayer() const {
    return this->players_[this->currentPlayerIndex_].get();
}


int Board::rollDice() const {
    return (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
}

void Board::movePlayer(int steps) {
    auto currentPlayer = this->getCurrentPlayer();
    if (this->willMoveCrossStart(currentPlayer, steps)) {
        currentPlayer->addMoney(CROSSING_START_BONUS);
    }
    currentPlayer->setPositionIdx(this->getNewPosition(currentPlayer, steps));
    this->fields_[currentPlayer->getPositionIdx()]->onPlayerEnter(currentPlayer);
}

void Board::nextPlayer() {
    currentPlayerIndex_ = (currentPlayerIndex_ + 1) % players_.size();
}

void Board::setCurrentPlayerIndex(int index) {
    this->currentPlayerIndex_ = index;
}

bool Board::willMoveCrossStart(Player* player, int steps) const {
    return this->getNewPosition(player, steps) < player->getPositionIdx();
}

int Board::getNewPosition(Player* player, int steps) const {
    int fieldsCount = this->fields_.size();
    int currentPosition = player->getPositionIdx();
    int newPosition = (currentPosition + steps) % fieldsCount;
    return newPosition;
}

const std::vector<std::shared_ptr<Field>>& Board::getFields() const {
    return this->fields_;
}