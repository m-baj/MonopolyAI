//
// Created by Maksymilian Baj on 13.11.2024.
//

#ifndef MONOPOLYAI_DECISION_H
#define MONOPOLYAI_DECISION_H

#include <format>
#include <string>
#include <functional>
#include <iostream>

#include "Constants.h"


class Player;

class DecisionSelector
{
public:
    virtual ~DecisionSelector() = default;
    explicit DecisionSelector(Player& player) : player_(player) {};

    virtual void requireSelection(const std::string& label,
                                  const std::vector<PlayerDecisionOutputs>&
                                  possibleDecisions) = 0;
private:
    Player& player_;
};

namespace ConsoleDecisionSelectorHelpers
{
    const std::map<PlayerDecisionOutputs, std::string> DECISION_TO_STRING = {
        {PlayerDecisionOutputs::BUY_FIELD, "bf"},
        {PlayerDecisionOutputs::MORTGAGE_FIELD, "mo"},
        {PlayerDecisionOutputs::UNMORTGAGE_FIELD, "umo"},
        {PlayerDecisionOutputs::BUY_HOUSE, "bh"},
        {PlayerDecisionOutputs::SELL_HOUSE, "sh"},
        {PlayerDecisionOutputs::BAIL_JAIL, "bj"},
        {PlayerDecisionOutputs::JAIL_DICE_ROLL, "jdr"},
        {PlayerDecisionOutputs::USE_GET_OUT_OF_JAIL_CARD, "jout"},
        {PlayerDecisionOutputs::NO_DECISION, "-"},
        {PlayerDecisionOutputs::THROW_DICE, "td"},
    };
    const std::map<PlayerDecisionOutputs, std::string> DECISION_SELECT_LABEL = {
        {PlayerDecisionOutputs::BUY_FIELD, std::format("Type '{}' to buy field", DECISION_TO_STRING.at(PlayerDecisionOutputs::BUY_FIELD))},
        {PlayerDecisionOutputs::MORTGAGE_FIELD, std::format("Type '{}' to mortgage a property", DECISION_TO_STRING.at(PlayerDecisionOutputs::MORTGAGE_FIELD))},
        {PlayerDecisionOutputs::UNMORTGAGE_FIELD, std::format("Type '{}' to un-mortgage a property", DECISION_TO_STRING.at(PlayerDecisionOutputs::UNMORTGAGE_FIELD))},
        {PlayerDecisionOutputs::BUY_HOUSE, std::format("Type '{}' to buy a house", DECISION_TO_STRING.at(PlayerDecisionOutputs::BUY_HOUSE))},
        {PlayerDecisionOutputs::SELL_HOUSE, std::format("Type '{}' to sell a house", DECISION_TO_STRING.at(PlayerDecisionOutputs::SELL_HOUSE))},
        {PlayerDecisionOutputs::BAIL_JAIL, std::format("Type '{}' to bail out of jail", DECISION_TO_STRING.at(PlayerDecisionOutputs::BAIL_JAIL))},
        {PlayerDecisionOutputs::JAIL_DICE_ROLL, std::format("Type '{}' to try to get out of jail with dice roll", DECISION_TO_STRING.at(PlayerDecisionOutputs::JAIL_DICE_ROLL))},
        {PlayerDecisionOutputs::USE_GET_OUT_OF_JAIL_CARD, std::format("Type '{}' to use \"Get Out Of Jail\" card", DECISION_TO_STRING.at(PlayerDecisionOutputs::USE_GET_OUT_OF_JAIL_CARD))},
        {PlayerDecisionOutputs::NO_DECISION, std::format("Type '{}' to don't do anything", DECISION_TO_STRING.at(PlayerDecisionOutputs::NO_DECISION))},
        {PlayerDecisionOutputs::THROW_DICE, std::format("Type '{}' to throw a dice", DECISION_TO_STRING.at(PlayerDecisionOutputs::THROW_DICE))},
    };

    void printDecisions(const std::vector<PlayerDecisionOutputs>& possibleDecisions);
    std::string receiveInput(std::istream& in);
}

class ConsoleDecisionSelector final : public DecisionSelector
{
public:
    explicit ConsoleDecisionSelector(Player& player) : DecisionSelector(player) {};

    void requireSelection(const std::string& label,
                          const std::vector<PlayerDecisionOutputs>&
                          possibleDecisions) override;

    static std::istream* in_stream;
};

// std::istream* ConsoleDecisionSelector::in_stream = &std::cin;

class AiDecisionSelector final : public DecisionSelector
{
public:
    explicit AiDecisionSelector(Player& player) : DecisionSelector(player) {};

    void requireSelection(const std::string& label,
                          const std::vector<PlayerDecisionOutputs>&
                          possibleDecisions) override {};
};

#endif //MONOPOLYAI_DECISION_H
