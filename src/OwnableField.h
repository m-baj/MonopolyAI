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
    void setOwner(Player* player);

    virtual std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const;

protected:
    Player* owner = nullptr;
    int baseBuyPrice;
};


#endif //MONOPOLYAI_OWNABLEFIELD_H
