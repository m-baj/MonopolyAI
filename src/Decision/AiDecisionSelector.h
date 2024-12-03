//
// Created by adrwal on 12/3/24.
// class that handles decision made by AI player
//

#ifndef AIDECISIONSELECTOR_H
#define AIDECISIONSELECTOR_H
#include <string>
#include <vector>

#include "DecisionSelector.h"


class AiDecisionSelector final : public DecisionSelector {
public:
    explicit AiDecisionSelector(Player& player) : DecisionSelector(player) {};

    void requireSelection(const std::string& label,
                          const std::vector<PlayerDecisionOutputs>&
                                  possibleDecisions) override {};
};


#endif//AIDECISIONSELECTOR_H
