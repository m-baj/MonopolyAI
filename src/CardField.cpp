//
// Created by adrwal on 11/6/24.
//

#include "CardField.h"

#include "Board.h"

std::optional<Decision> CardField::onPlayerEnter(Player *player) {
    auto decision = this->drawCard(player);
    if (decision.has_value()) {
        // TODO: Implement case when drawing carded required some player input. e.g. player don't have enough money.
    }
    board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::SELL_HOUSE);
    board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::MORTGAGE_FIELD);
    board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::UNMORTGAGE_FIELD);
    board.currentPlayerPossibleDecisions.insert(PlayerDecisionOutputs::THROW_DICE);
    return std::nullopt;
}

std::optional<Decision> CardField::drawCard(Player *player) {
    return std::nullopt;
}
