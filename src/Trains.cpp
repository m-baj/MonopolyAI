//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Trains.h"
#include "Player.h"

void Trains::onPlayerEnter(Player *player) {
    std::optional<Player *> owner = getOwner();
    if (owner.has_value() && owner.value() != player) {
        int rent = calculateRentPrice(owner.value());
        player->payTo(owner.value(), rent);
    }
}
