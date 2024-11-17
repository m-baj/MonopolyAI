//
// Created by adrwal on 11/6/24.
//

#ifndef CARDFIELD_H
#define CARDFIELD_H
#include "Field.h"

#include <utility>


class CardField final : public Field {
public:
    explicit CardField(const std::string& name, Board& board)
        : Field(name, board)
    {
    }
    std::vector<PlayerDecisionOutputs> onPlayerEnter(Player* player) override;
    void drawCard(Player* player);
};



#endif //CARDFIELD_H
