//
// Created by adrwal on 11/3/24.
//


#include "Player.h"

#include "Property.h"


std::string Player::getName() const
{
    return this->name;
}

int Player::getMoney() const
{
    return this->money;
}

int Player::getPositionIdx() const
{
    return this->positionIdx;
}

const std::vector<std::shared_ptr<Property>>& Player::getProperties() const {
    return this->properties;
}

const std::vector<std::shared_ptr<Utilities>>& Player::getUtilities() const {
    return this->utilities;
}

const std::vector<std::shared_ptr<Trains>>& Player::getTrains() const {
    return this->trains;
}

void Player::setPositionIdx(int positionIdx)
{
    this->positionIdx = positionIdx;
}

void Player::pushProperty(std::shared_ptr<Property> property)
{
    this->properties.push_back(property);
}

void Player::addMoney(int amount)
{
    this->money += amount;
}

void Player::declareBankruptcy() {
    isBankrupt = true;
}

void Player::saveTurnDecision(PlayerDecisionOutputs decision)
{
    decisionsMadeThisTurn.push_back(decision);
}

void Player::clearTurnDecisions()
{
    decisionsMadeThisTurn = {};
}

void Player::payTo(Player* player, int amount)
{
    return pay(amount, player);
}

void Player::payToBank(int amount)
{
    return pay(amount);
}

void Player::pay(int amount, Player* player)
{
    bool payed = false;
    while (!payed) {
        if (money - amount >= 0)
        {
            money -= amount;
            if (player)
                player->addMoney(amount);
            payed = true;
        }
        else {
            createDecisionSelector()
                ->requireSelection(
                    "You do not have enough money to pay. Sell something",
                    {PlayerDecisionOutputs::SELL_HOUSE, PlayerDecisionOutputs::MORTGAGE_FIELD}
                );
        }
    }

    // if (money - amount >= 0)
    // {
    //     money -= amount;
    //     if (player)
    //         player->addMoney(amount);
    //     return std::nullopt;
    // }
    // else
    // {
    //     // TODO: implement logic when player does not have enough money to pay
    //     return std::nullopt;
    // }
}

std::unique_ptr<DecisionSelector> ConsolePlayer::createDecisionSelector()
{
    return std::make_unique<ConsoleDecisionSelector>();
}

std::unique_ptr<DecisionSelector> AiPlayer::createDecisionSelector()
{
    return std::make_unique<AiDecisionSelector>();
}

bool Player::ownsAllPropertiesOf(Color color) const {
    int numberOfProperties = 0;
    for (const auto& property : properties)
    {
        if (property->getColor() == color)
        {
            numberOfProperties++;
        }
    }
    return numberOfProperties == COLOR_TO_FIELD_COUNT.at(color);
}

int Player::getNumberOfTrains() const {
    return trains.size();
}

std::vector<PlayerDecisionOutputs> Player::getMadeTurnDecisions() const
{
    return decisionsMadeThisTurn;
}

void Player::pushTrain(std::shared_ptr<Trains> train) {
    trains.push_back(train);
}



