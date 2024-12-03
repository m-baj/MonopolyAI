//
// Created by adrwal on 11/6/24.
// class representing field that sends player to jail
//

#ifndef GOTOJAILFIELD_H
#define GOTOJAILFIELD_H
#include "Field.h"


class GoToJailField final : public Field {
public:
    explicit GoToJailField(const std::string& name, Board& board)
        : Field(name, board) {
    }

    std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const override;
};


#endif//GOTOJAILFIELD_H
