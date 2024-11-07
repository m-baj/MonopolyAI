//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "Bank.h"

Bank::Bank() = default;

void Bank::payMoneyTo(Player* player, int amount) const
{
    player->addMoney(amount);
}
