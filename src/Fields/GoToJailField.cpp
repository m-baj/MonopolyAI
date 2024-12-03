//
// Created by adrwal on 11/6/24.
//

#include "GoToJailField.h"

std::vector<PlayerDecisionOutputs> GoToJailField::getFieldDecisions(Player* player) const {
    std::vector<PlayerDecisionOutputs> decisions = {PlayerDecisionOutputs::JAIL_DICE_ROLL};
    // TODO: Check if player has get out of jail card
    // TODO: Check if player has enough money to bail
    return decisions;
}
