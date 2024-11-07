//
// Created by Maksymilian Baj on 07.11.2024.
//

#ifndef MONOPOLYAI_BANK_H
#define MONOPOLYAI_BANK_H
#include "Player.h"


class Bank {
public:
    Bank();
    void payMoneyTo(Player* player, int amount) const;
};


#endif //MONOPOLYAI_BANK_H
