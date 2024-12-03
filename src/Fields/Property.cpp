//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Property.h"
#include "../Player.h"


void Property::onPlayerEnter(Player* player) {
    if (owner_ && owner_ != player && !isMortgaged_) {// player has to pay rent to owner_
        player->payTo(owner_, calculateRentPrice());
    }
}

std::vector<PlayerDecisionOutputs> Property::getFieldDecisions(Player* player) const {
    auto baseDecisions = OwnableField::getFieldDecisions(player);

    if (canBuyHouseHere(player)) {
        baseDecisions.push_back(PlayerDecisionOutputs::BUY_HOUSE);
    }
    return baseDecisions;
}

bool Property::canBuyHouseHere(Player* player) const {
    if (owner_ != player) {
        return false;
    }
    if (isMortgaged_) {
        return false;
    }
    if (numberOfHouses_ == MAX_NUMBER_OF_HOUSES) {
        return false;
    }
    if (calculateNextHousePrice() > player->getMoney()) {
        return false;
    }
    // TODO: check if player already bought house this turn
    // TODO: check if property is newly bought
    return true;
}

int Property::calculateNextHousePrice() const {
    if (numberOfHouses_ < MAX_NUMBER_OF_HOUSES - 1) {
        return HOUSE_PRICE;
    }
    return HOTEL_PRICE;
}

int Property::calculateRentPrice() const {
    if (owner_->ownsAllPropertiesOf(color_)) {
        return baseRentPrice_ * 2;
    }
    return baseRentPrice_;
}

Color Property::getColor() const {
    return color_;
}

void Property::setMortgaged(bool isMortgaged) {
    this->isMortgaged_ = isMortgaged;
}

bool Property::getIsMortgaged() const {
    return isMortgaged_;
}

int Property::getMortgagePrice() const {
    return mortgagePrice_;
}

int Property::getNumberOfHouses() const {
    return numberOfHouses_;
}

void Property::addHouse() {
    numberOfHouses_++;
}

bool Property::getHasHotel() const {
    return hasHotel_;
}

void Property::setHasHotel(bool hasHotel) {
    Property::hasHotel_ = hasHotel;
}
