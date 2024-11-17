//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Property.h"
#include "Board.h"

const double UNMORTGAGE_INTEREST_MULTIPLIER = 1.1;

std::vector<PlayerDecisionOutputs> Property::onPlayerEnter(Player *player) {
    std::vector<PlayerDecisionOutputs> decisions = {
        PlayerDecisionOutputs::SELL_HOUSE,
        PlayerDecisionOutputs::THROW_DICE,
        PlayerDecisionOutputs::MORTGAGE_FIELD,
        PlayerDecisionOutputs::UNMORTGAGE_FIELD
    };

    if (owner) {
        handleOwnedProperty(player, decisions);
    }

    return decisions;
}

void Property::handleOwnedProperty(Player *player, std::vector<PlayerDecisionOutputs> &decisions) {
    if (owner != player && !isMortgaged)    // player has to pay rent to owner
    {
        player->payTo(owner, calculateRentPrice());
    }
    else if (owner == player && !isMortgaged)   // player is the owner
    {
        return handleUpgradableProperty(player, decisions);
    }
    // else if (owner == player && owner->getMoney() >= mortgagePrice) // if player is the owner and property is mortgaged
    // {
    //     return unmortgageDecision(player);
    // }
    // else    // if player is the owner and does not have enough money to unmortgage or property is mortgaged by another player
    //     return std::nullopt;
}

void Property::handleUpgradableProperty(Player *owner, std::vector<PlayerDecisionOutputs> &decisions)
{
    // Decision decision;
    if (numberOfHouses < MAX_NUMBER_OF_HOUSES && owner->getMoney() >= HOUSE_PRICE) // if player can buy a house
    {
        decisions.push_back(PlayerDecisionOutputs::BUY_HOUSE);
        // board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::BUY_HOUSE);
        // addBuyHouseDecision(owner, decision);
    }
    // if (numberOfHouses > 0)
    // {
    //     addSellHouseDecision(owner, decision);
    // }
    // if (numberOfHouses == MAX_NUMBER_OF_HOUSES && owner->getMoney() >= HOTEL_PRICE) // if player can buy a hotel
    // {
    //     addBuyHotelDecision(owner, decision);
    // }
    // else if (hasHotel)
    // {
    //     return sellHotelDecision(owner);
    // }
    // return decision;
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
