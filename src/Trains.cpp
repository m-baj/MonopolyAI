//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Trains.h"
#include "Player.h"

std::optional<Decision> Trains::onPlayerEnter(Player *player) {
    if (owner && owner != player)
    {
        int rent = calculateRentPrice();
        player->payTo(owner, rent);
        return std::nullopt;
    }
    else if (!owner)
        return handleUnownedTrain(player);

    return std::nullopt;
}

std::optional<Decision> Trains::handleUnownedTrain(Player *player) {
    Decision decision;
    decision.addChoice(Decision::Choice("Buy trains", [this, player]() {
        player->payToBank(baseBuyPrice);
        player->pushTrain(std::make_shared<Trains>(*this));
        owner = player;
    }));
    return decision;
}

int Trains::calculateRentPrice() const {
    int trainsOwned = owner->getNumberOfTrains();
    int multiplier = 1 << (trainsOwned - 1);
    return BASE_RENT_FOR_TRAIN * multiplier;
}
