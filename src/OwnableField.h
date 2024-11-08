//
// Created by bajma on 08.11.2024.
//

#ifndef MONOPOLYAI_OWNABLEFIELD_H
#define MONOPOLYAI_OWNABLEFIELD_H


#include "Field.h"

class OwnableField : public Field {
public:
    OwnableField(const std::string& name, Board& board)
        : Field(name, board) {};

    virtual void onPlayerEnter(Player* player) = 0;
    std::optional<Player*> getOwner() const;
};


#endif //MONOPOLYAI_OWNABLEFIELD_H
