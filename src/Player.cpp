//
// Created by adrwal on 11/3/24.
//

#include "Player.h"
#include <algorithm>
#include "board.h"

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

const std::vector<std::shared_ptr<OwnableField>>& Player::getOwnableFields() const
{
    return this->ownableFields;
}

void Player::setPositionIdx(int positionIdx)
{
    this->positionIdx = positionIdx;
}

void Player::pushOwnable(std::shared_ptr<OwnableField> ownable)
{
    this->ownableFields.push_back(ownable);
}

void Player::addMoney(int amount)
{
    this->money += amount;
}

void Player::payTo(Player* player, int amount)
{
    pay(amount, player);
}

void Player::payToBank(int amount)
{
    pay(amount);
}

void Player::pay(int amount, Player* player)
{
    if (money - amount >= 0)
    {
        money -= amount;
        if (player)
        {
            player->addMoney(amount);
        }
    }
    else
    {
        // TODO: implement logic when player does not have enough money to pay
    }
}

bool Player::ownsAllPropertiesOf(Color color) const {
    auto amount = std::count_if(ownableFields.begin(), ownableFields.end(),
                                [color](const auto& field) {
        auto property = std::dynamic_pointer_cast<Property>(field);
        return property && property->getColor() == color;
    });
    return amount == COLOR_TO_FIELD_COUNT.at(color);
}

