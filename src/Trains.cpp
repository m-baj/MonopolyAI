//
// Created by Maksymilian Baj on 7.11.24.
//

#include "Trains.h"

#include "Board.h"
#include "Constants.h"
#include "Player.h"

void Trains::onPlayerEnter(Player *player) {
    // std::vector<PlayerDecisionOutputs> decisions = {
    //     PlayerDecisionOutputs::SELL_HOUSE,
    //     PlayerDecisionOutputs::THROW_DICE,
    //     PlayerDecisionOutputs::MORTGAGE_FIELD,
    //     PlayerDecisionOutputs::UNMORTGAGE_FIELD
    // };

    if (owner && owner != player)
    {
        int rent = calculateRentPrice();
        player->payTo(owner, rent);
    }
    // else if (!owner)
    //     decisions.push_back(PlayerDecisionOutputs::BUY_FIELD);

    // return decisions;
}

// std::optional<Decision> Trains::handleUnownedTrain(Player *player) {
//     Decision decision;
//     decision.addChoice(Decision::Choice("Buy trains", [this, player]() {
//         player->payToBank(baseBuyPrice);
//         player->pushTrain(std::make_shared<Trains>(*this));
//         owner = player;
//     }));
//     return decision;
// }

int Trains::calculateRentPrice() const {
    int trainsOwned = owner->getNumberOfTrains();
    int multiplier = 1 << (trainsOwned - 1);
    return BASE_RENT_FOR_TRAIN * multiplier;
}

std::vector<PlayerDecisionOutputs> Trains::getFieldDecisions(Player* player) const
{
    auto baseDecisions = Field::getFieldDecisions(player);

    if(!owner && player->getMoney() >= baseBuyPrice)
        baseDecisions.push_back(PlayerDecisionOutputs::BUY_FIELD);
}
