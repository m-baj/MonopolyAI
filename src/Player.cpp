//
// Created by adrwal on 11/3/24.
//


#include "Player.h"

#include "Decision/AiDecisionSelector.h"
#include "Decision/ConsoleDecisionSelector.h"
#include "Fields/Property.h"


std::string Player::getName() const {
    return this->name_;
}

int Player::getMoney() const {
    return this->money_;
}

int Player::getPositionIdx() const {
    return this->positionIdx_;
}

const std::vector<std::shared_ptr<Property>>& Player::getProperties() const {
    return this->properties_;
}

const std::vector<std::shared_ptr<Utilities>>& Player::getUtilities() const {
    return this->utilities_;
}

const std::vector<std::shared_ptr<Trains>>& Player::getTrains() const {
    return this->trains_;
}

void Player::setPositionIdx(int positionIdx) {
    this->positionIdx_ = positionIdx;
}

void Player::pushProperty(std::shared_ptr<Property> property) {
    this->properties_.push_back(property);
}

void Player::addMoney(int amount) {
    this->money_ += amount;
}

void Player::declareBankruptcy() {
    isBankrupt_ = true;
}

void Player::saveTurnDecision(PlayerDecisionOutputs decision) {
    decisionsMadeThisTurn_.push_back(decision);
}

void Player::clearTurnDecisions() {
    decisionsMadeThisTurn_ = {};
}

void Player::payTo(Player* player, int amount) {
    return pay(amount, player);
}

void Player::payToBank(int amount) {
    return pay(amount);
}

void Player::pay(int amount, Player* player) {
    bool payed = false;
    while (!payed) {
        if (money_ - amount >= 0) {
            money_ -= amount;
            if (player)
                player->addMoney(amount);
            payed = true;
        } else {
            createDecisionSelector()
                    ->requireSelection(
                            "You do not have enough money_ to pay. Sell something",
                            {PlayerDecisionOutputs::SELL_HOUSE, PlayerDecisionOutputs::MORTGAGE_FIELD});
        }
    }
}

std::unique_ptr<DecisionSelector> ConsolePlayer::createDecisionSelector() {
    return std::make_unique<ConsoleDecisionSelector>(*this);
}

std::unique_ptr<DecisionSelector> AiPlayer::createDecisionSelector() {
    return std::make_unique<AiDecisionSelector>(*this);
}

bool Player::ownsAllPropertiesOf(Color color) const {
    int numberOfProperties = 0;
    for (const auto& property: properties_) {
        if (property->getColor() == color) {
            numberOfProperties++;
        }
    }
    return numberOfProperties == COLOR_TO_FIELD_COUNT.at(color);
}

int Player::getNumberOfTrains() const {
    return trains_.size();
}

std::vector<PlayerDecisionOutputs> Player::getMadeTurnDecisions() const {
    return decisionsMadeThisTurn_;
}

void Player::pushTrain(std::shared_ptr<Trains> train) {
    trains_.push_back(train);
}
