//
// Created by adrwal on 11/3/24.
//

#ifndef TRAINS_H
#define TRAINS_H
#include "OwnableField.h"

const int BASE_RENT_FOR_TRAIN = 25;

class Trains final : public OwnableField {
public:
    Trains(const std::string& name, Board& board, int baseBuyPrice)
        : OwnableField(name, board, baseBuyPrice) {}
    std::vector<PlayerDecisionOutputs> onPlayerEnter(Player* player) override;
    int calculateRentPrice() const;

// private:
//     std::optional<Decision> handleUnownedTrain(Player* player);
};



#endif //TRAINS_H
