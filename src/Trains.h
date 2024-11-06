//
// Created by adrwal on 11/3/24.
//

#ifndef TRAINS_H
#define TRAINS_H
#include "Field.h"


class Trains final : public Field{
public:
    Trains(const std::string& name, Board& board)
        : Field(name, board)
    {
    }
    void onPlayerEnter() override{};
};



#endif //TRAINS_H
