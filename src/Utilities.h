//
// Created by adrwal on 11/3/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H
#include "Field.h"


class Player;
class Board;

class Utilities final : public Field {
public:
    Utilities(const std::string& name, Board& board)
        : Field(name, board)
    {
    }
    void onPlayerEnter(Player* player) override {};
};



#endif //UTILITIES_H
