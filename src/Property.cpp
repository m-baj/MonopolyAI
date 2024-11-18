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
    auto baseDecisions = Field::getFieldDecisions(player);

    if (canBuyThisProperty(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::BUY_FIELD);
    }
    else if (canBuyHouseHere(player))
    {
        baseDecisions.push_back(PlayerDecisionOutputs::BUY_HOUSE);
    }
    return baseDecisions;
}

// void Property::handleOwnedProperty(Player *player) {
//     if (owner != player && !isMortgaged)    // player has to pay rent to owner
//     {
//         player->payTo(owner, calculateRentPrice());
//     }
//     // else if (owner == player && !isMortgaged)   // player is the owner
//     // {
//     //     return handleUpgradableProperty(player);
//     // }
//     // else if (owner == player && owner->getMoney() >= mortgagePrice) // if player is the owner and property is mortgaged
//     // {
//     //     return unmortgageDecision(player);
//     // }
//     // else    // if player is the owner and does not have enough money to unmortgage or property is mortgaged by another player
//     //     return std::nullopt;
// }

// void Property::handleUpgradableProperty(Player *owner)
// {
//     // Decision decision;
//     if (numberOfHouses < MAX_NUMBER_OF_HOUSES && owner->getMoney() >= HOUSE_PRICE) // if player can buy a house
//     {
//         decisions.push_back(PlayerDecisionOutputs::BUY_HOUSE);
//         // board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::BUY_HOUSE);
//         // addBuyHouseDecision(owner, decision);
//     }
//     // if (numberOfHouses > 0)
//     // {
//     //     addSellHouseDecision(owner, decision);
//     // }
//     // if (numberOfHouses == MAX_NUMBER_OF_HOUSES && owner->getMoney() >= HOTEL_PRICE) // if player can buy a hotel
//     // {
//     //     addBuyHotelDecision(owner, decision);
//     // }
//     // else if (hasHotel)
//     // {
//     //     return sellHotelDecision(owner);
//     // }
//     // return decision;
// }

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

bool Property::canBuyThisProperty(Player* player) const
{
    return !owner && player->getMoney() >= baseBuyPrice;
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

// std::optional<Decision> Property::handleUnownedProperty(Player *player) {
//     // Decision decision;
//     // decision.addChoice(Decision::Choice("Buy property", [this, player]() {
//     //     player->payToBank(baseBuyPrice);
//     //     player->pushProperty(std::make_shared<Property>(*this));
//     //     owner = player;
//     // }));
//     // return decision;
//     return std::nullopt;
// }

// Decision Property::unmortgageDecision(Player *player) {
//     Decision decision;
//     decision.addChoice(Decision::Choice("Unmortgage", [this, player](){
//         player->payToBank(mortgagePrice * UNMORTGAGE_INTEREST_MULTIPLIER);
//         isMortgaged = false;
//     }));
//     return decision;
// }
//
// void Property::addBuyHouseDecision(Player *player, Decision& decision) {
//     decision.addChoice(Decision::Choice("Buy house", [this, player](){
//         player->payToBank(HOUSE_PRICE);
//         numberOfHouses++;
//     }));
// }
//
// void Property::addSellHouseDecision(Player *player, Decision& decision) {
//     decision.addChoice(Decision::Choice("Sell house", [this, player](){
//         player->addMoney(HOUSE_PRICE);
//         numberOfHouses--;
//     }));
// }
//
// void Property::addBuyHotelDecision(Player *player, Decision& decision) {
//     decision.addChoice(Decision::Choice("Buy hotel", [this, player](){
//         player->payToBank(HOTEL_PRICE);
//         numberOfHouses = 0;
//         hasHotel = true;
//     }));
// }
//
// Decision Property::sellHotelDecision(Player *player) {
//     Decision decision;
//     decision.addChoice(Decision::Choice("Sell hotel", [this, player](){
//         player->addMoney(HOTEL_PRICE);
//         hasHotel = false;
//     }));
//     return decision;
// }

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
