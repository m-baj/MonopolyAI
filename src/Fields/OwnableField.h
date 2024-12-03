//
// Created by Maksymilian Baj on 08.11.2024.
// Class representing a filed that can be owned by a player.
//

#ifndef MONOPOLYAI_OWNABLEFIELD_H
#define MONOPOLYAI_OWNABLEFIELD_H

#include "Field.h"


class OwnableField : public Field {
public:
    OwnableField(const std::string& name, Board& board, int baseBuyPrice)
        : Field(name, board), baseBuyPrice_(baseBuyPrice) {};

    std::optional<Player*> getOwner() const;
    void setOwner(Player* player);

    virtual std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const;

protected:
    Player* owner_ = nullptr;
    int baseBuyPrice_;
};


#endif//MONOPOLYAI_OWNABLEFIELD_H
