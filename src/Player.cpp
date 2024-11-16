//
// Created by adrwal on 11/3/24.
//

#include "Player.h"
#include "Board.h"
#include "GameCli.h"

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
            Decision decision;
            // TODO: For each house owned by player, add a choice to sell it
            // TODO: For each field owned by player, add a choice to mortgage it
            if (decision.getChoices().empty()) {
                declareBankruptcy();
                return;
            }
            board.getPlayedGame()
                ->createChoiceSelection(decision, "You do not have enough money to pay. Choose one of the following options:")
                ->requireSelection();
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

void Player::pushTrain(std::shared_ptr<Trains> train) {
    trains.push_back(train);
}



