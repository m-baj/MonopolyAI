//
// Created by Maksymilian Baj on 08.11.2024.
//

#ifndef MONOPOLYAI_OWNABLEFIELD_H
#define MONOPOLYAI_OWNABLEFIELD_H


#include "Field.h"

class OwnableField : public Field {
public:
    OwnableField(const std::string& name, Board& board, int baseBuyPrice)
        : Field(name, board), baseBuyPrice(baseBuyPrice) {};

    std::optional<Player*> getOwner() const;

private:
    int baseBuyPrice;
    Player* owner = nullptr;
};


#endif //MONOPOLYAI_OWNABLEFIELD_H
