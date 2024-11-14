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
    std::optional<Decision> onPlayerEnter(Player* player) override {return std::nullopt;};
};



#endif //CARDFIELD_H
