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
    void onPlayerEnter(Player* player) override {};
};



#endif //UTILITIES_H
