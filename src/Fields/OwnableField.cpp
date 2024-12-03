//
// Created by Maksymilian Baj on 08.11.2024.
//

#include "OwnableField.h"

std::optional<Player*> OwnableField::getOwner() const {
    if (owner == nullptr) {
        return std::nullopt;
    }
    return owner;
}

void OwnableField::setOwner(Player* player) {
    owner = player;
}

std::vector<PlayerDecisionOutputs> OwnableField::getFieldDecisions(Player* player) const {
    auto decisions = Field::getFieldDecisions(player);
    // TODO: Check if field can be bought
    return decisions;
}
