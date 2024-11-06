//
// Created by adrwal on 11/3/24.
//

#ifndef UTILITIES_H
#define UTILITIES_H
#include "Field.h"


class Utilities final : public Field {
public:
    Utilities(const std::string& name, Board& board)
        : Field(name, board)
    {
    }
    void onPlayerEnter() override {};
};



#endif //UTILITIES_H
