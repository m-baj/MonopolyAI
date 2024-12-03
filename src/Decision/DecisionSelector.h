//
// Created by Maksymilian Baj on 13.11.2024.
// Class that handles the decision-making process for players_
//

#ifndef MONOPOLYAI_DECISION_H
#define MONOPOLYAI_DECISION_H

#include "../Constants.h"
#include <format>
#include <string>
#include <vector>


class Player;

class DecisionSelector {
public:
    virtual ~DecisionSelector() = default;
    explicit DecisionSelector(Player& player) : player_(player) {};

    virtual void requireSelection(const std::string& label,
                                  const std::vector<PlayerDecisionOutputs>&
                                          possibleDecisions) = 0;

private:
    Player& player_;
};


#endif//MONOPOLYAI_DECISION_H
