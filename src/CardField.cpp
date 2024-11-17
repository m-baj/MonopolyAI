//
// Created by adrwal on 11/6/24.
//

#include "CardField.h"

#include "Board.h"

std::vector<PlayerDecisionOutputs> CardField::onPlayerEnter(Player *player) {
    this->drawCard(player);

    return {
        PlayerDecisionOutputs::SELL_HOUSE,
        PlayerDecisionOutputs::MORTGAGE_FIELD,
        PlayerDecisionOutputs::UNMORTGAGE_FIELD,
        PlayerDecisionOutputs::THROW_DICE
    };
}

void CardField::drawCard(Player *player) {

}
