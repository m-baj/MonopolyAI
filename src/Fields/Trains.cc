//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Trains.h"

#include "../Board.h"
#include "../Constants.h"
#include "../Player.h"

void Trains::onPlayerEnter(Player* player) {
    if (owner_ && owner_ != player) {
        int rent = calculateRentPrice();
        player->payTo(owner_, rent);
    }
}

int Trains::calculateRentPrice() const {
    int trainsOwned = owner_->getNumberOfTrains();
    int multiplier = 1 << (trainsOwned - 1);
    return BASE_RENT_FOR_TRAIN * multiplier;
}
