//
// Created by adrwal on 11/3/24.
//

#ifndef TRAINS_H
#define TRAINS_H
#include "OwnableField.h"

class Trains final : public OwnableField {
public:
    Trains(const std::string& name, Board& board, int baseBuyPrice)
        : OwnableField(name, board, baseBuyPrice) {}

    int calculateRentPrice() const;

    void onPlayerEnter(Player* player) override;
};



#endif //TRAINS_H
