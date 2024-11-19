//
// Created by Maksymilian Baj on 13.11.2024.
//

#ifndef MONOPOLYAI_DECISION_H
#define MONOPOLYAI_DECISION_H

#include <string>
#include <functional>

#include "Constants.h"


class DecisionSelector
{
public:
    virtual ~DecisionSelector() = default;
    DecisionSelector() = default;

    virtual void requireSelection(const std::string& label,
                                  const std::vector<PlayerDecisionOutputs>&
                                  possibleDecisions) = 0;
};

class ConsoleDecisionSelector final : public DecisionSelector
{
public:
    void requireSelection(const std::string& label,
                          const std::vector<PlayerDecisionOutputs>&
                          possibleDecisions) override;
};

class AiDecisionSelector final : public DecisionSelector
{
public:
    void requireSelection(const std::string& label,
                          const std::vector<PlayerDecisionOutputs>&
                          possibleDecisions) override {};
};

#endif //MONOPOLYAI_DECISION_H
