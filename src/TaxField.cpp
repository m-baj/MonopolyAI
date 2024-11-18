//
// Created by adrwal on 11/6/24.
//

const int TAX_AMOUNT = 200;

#include "TaxField.h"
#include "Player.h"
#include "Board.h"

void TaxField::onPlayerEnter(Player* player)
{
    player->payToBank(TAX_AMOUNT);

    // return {
    //     PlayerDecisionOutputs::SELL_HOUSE,
    //     PlayerDecisionOutputs::THROW_DICE,
    //     PlayerDecisionOutputs::MORTGAGE_FIELD,
    //     PlayerDecisionOutputs::UNMORTGAGE_FIELD,
    // };
}
