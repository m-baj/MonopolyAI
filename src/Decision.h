//
// Created by Maksymilian Baj on 13.11.2024.
//

#ifndef MONOPOLYAI_DECISION_H
#define MONOPOLYAI_DECISION_H

#include <string>
#include <functional>

#include "Constants.h"


// class Decision {
// public:
//     struct Choice
//     {
//         std::string description;
//         std::function<void()> action;
//     };
//
//     Decision() = default;
//     std::vector<Choice> getChoices() const;
//     void addChoice(const Choice& choice);
//
// private:
//     std::vector<Choice> choices = {};
// };

// class ChoiceSelection {
// public:
//     virtual ~ChoiceSelection() = default;
//     explicit ChoiceSelection(const Decision& decision, const std::string& label)
//         : decision(decision), label(label) {};
//
//     const Decision& getDecision() const;
//     const std::string& getLabel() const;
//
//     virtual void requireSelection() = 0;
//
// private:
//     Decision decision;
//     std::string label;
// };
//
// class ConsoleChoiceSelection final : public ChoiceSelection {
// public:
//     ConsoleChoiceSelection(const Decision& decision, const std::string& label)
//         : ChoiceSelection(decision, label) {};
//
//     void requireSelection() override;
// };
//
// class AiChoiceSelection final : public ChoiceSelection
// {
//     AiChoiceSelection(const Decision& decision, const std::string& label)
//         : ChoiceSelection(decision, label) {};
//
//     // TODO: Implement AI logic of choosing decision
//     void requireSelection() override { getDecision().getChoices()[0].action(); };
// };

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
