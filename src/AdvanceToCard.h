//
// Created by Maksymilian Baj on 25.01.2025.
//

#ifndef MONOPOLYAI_ADVANCETOCARD_H
#define MONOPOLYAI_ADVANCETOCARD_H

#include "Card.h"

class AdvanceToCard final : public Card {
public:
    AdvanceToCard(std::string description, int destinationIdx)
        : Card(description, [destinationIdx](Player* player) {
            player->setPositionIdx(destinationIdx);
        }) {};
};


#endif//MONOPOLYAI_ADVANCETOCARD_H
