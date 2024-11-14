//
// Created by adrwal on 11/3/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H
#include "OwnableField.h"


class Player;
class Board;

class Utilities final : public OwnableField {
public:
    Utilities(const std::string& name, Board& board, int baseBuyPrice)
        : OwnableField(name, board, baseBuyPrice) {}
    std::optional<Decision> onPlayerEnter(Player* player) override {return std::nullopt;};
};



#endif //UTILITIES_H
