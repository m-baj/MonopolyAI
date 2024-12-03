//
// Created by adrwal on 11/6/24.
// Represents a field where player draws a card.
//

#ifndef CARDFIELD_H
#define CARDFIELD_H

#include "Field.h"


class CardField final : public Field {
public:
    explicit CardField(const std::string& name, Board& board)
        : Field(name, board) {
    }
    ~CardField() override = default;

    void onPlayerEnter(Player* player) override;
    void drawCard(Player* player);
};


#endif//CARDFIELD_H
