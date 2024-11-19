//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Property.h"
#include "Player.h"

const double UNMORTGAGE_INTEREST_MULTIPLIER = 1.1;

void Property::onPlayerEnter(Player* player) {
    if (owner && owner != player && !isMortgaged) {    // player has to pay rent to owner
        player->payTo(owner, calculateRentPrice());
    }
}

std::vector<PlayerDecisionOutputs> Property::getFieldDecisions(Player* player) const
{
    auto baseDecisions = OwnableField::getFieldDecisions(player);

    if (canBuyHouseHere(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::BUY_HOUSE);
    }
    return baseDecisions;
}

bool Property::canBuyHouseHere(Player* player) const
{
    if (owner != player)
    {
        return false;
    }
    if(isMortgaged)
    {
        return false;
    }
    if (numberOfHouses == MAX_NUMBER_OF_HOUSES)
    {
        return false;
    }
    if(calculateNextHousePrice() > player->getMoney())
    {
        return false;
    }
    // TODO: check if player already bought house this turn
    // TODO: check if property is newly bought
    return true;
}

int Property::calculateNextHousePrice() const
{
    if (numberOfHouses < MAX_NUMBER_OF_HOUSES - 1)
    {
        return HOUSE_PRICE;
    }
    return HOTEL_PRICE;
}

int Property::calculateRentPrice() const
{
    if (owner->ownsAllPropertiesOf(color))
    {
        return baseRentPrice * 2;
    }
    return baseRentPrice;
}

Color Property::getColor() const
{
    return color;
}

void Property::setMortgaged(bool isMortgaged) {
    this->isMortgaged = isMortgaged;
}

bool Property::getIsMortgaged() const {
    return isMortgaged;
}

int Property::getMortgagePrice() const {
    return mortgagePrice;
}

int Property::getNumberOfHouses() const {
    return numberOfHouses;
}

void Property::addHouse() {
    numberOfHouses++;
}

bool Property::getHasHotel() const {
    return hasHotel;
}

void Property::setHasHotel(bool hasHotel) {
    Property::hasHotel = hasHotel;
}
