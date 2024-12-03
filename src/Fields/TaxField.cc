//
// Created by adrwal on 11/6/24.
//

#include "TaxField.h"
#include "../Player.h"

void TaxField::onPlayerEnter(Player* player) {
    player->payToBank(TAX_AMOUNT);
}
