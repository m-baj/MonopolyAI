//
// Created by adrwal on 11/3/24.
//

#include "Player.h"

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

const std::vector<std::shared_ptr<Property>>& Player::getProperties() const
{
    return this->properties;
}

const std::vector<std::shared_ptr<Utilities>>& Player::getUtilities() const
{
    return this->utilities;
}

const std::vector<std::shared_ptr<Trains>>& Player::getTrains() const
{
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

void Player::payMoneyTo(Player *player, int amount) {
    if (money - amount >= 0)
    {
        money -= amount;
        player->addMoney(amount);
    }
    else
    {
        // todo: implement logic when player does not have enough money to pay
    }
}

void Player::payToBank(int amount)
{
    if (money - amount >= 0)
    {
        money -= amount;
    }
    else
    {

    }
}
