//
// Created by adrwal on 12/3/24.
//

#include "ConsoleDecisionSelector.h"

#include <iostream>
#include <algorithm>

#include "../Player.h"

std::istream* ConsoleDecisionSelector::in_stream = &std::cin;
void ConsoleDecisionSelectorHelpers::printDecisions(const std::vector<PlayerDecisionOutputs>& possibleDecisions)
{
    for (auto decision : possibleDecisions)
    {
        std::cout << DECISION_SELECT_LABEL.at(decision) << std::endl;
    }
}

PlayerDecisionOutputs ConsoleDecisionSelectorHelpers::receiveInput(std::istream& in, const std::vector<PlayerDecisionOutputs>& possibleDecisions)
{
    std::string decision;
    std::map<std::string, PlayerDecisionOutputs>::const_iterator decision_enum;

    do
    {
        std::cout << "Enter decision: ";
        in >> decision;
        decision_enum = STRING_TO_DECISION.find(decision);
        if (decision_enum == STRING_TO_DECISION.end() || std::ranges::find(possibleDecisions, decision_enum->second) == possibleDecisions.end())
        {
            std::cout << "Invalid decision. Please try again." << std::endl;
        }
    } while (decision_enum == STRING_TO_DECISION.end() || std::ranges::find(possibleDecisions, decision_enum->second) == possibleDecisions.end());

    return decision_enum->second;
}


void ConsoleDecisionSelector::requireSelection(const std::string& label,
                                               const std::vector<PlayerDecisionOutputs>&
                                               possibleDecisions)
{
    // TODO: Implement decision selection through console. All decisions in `possibleDecisions` should be handled here, as well as decisions following from them.

    if (possibleDecisions.empty())
    {
        return;
    }

    ConsoleDecisionSelectorHelpers::printDecisions(possibleDecisions);
    PlayerDecisionOutputs decision = ConsoleDecisionSelectorHelpers::receiveInput(*ConsoleDecisionSelector::in_stream, possibleDecisions);
    player_.saveTurnDecision(decision);

    switch (decision)
    {
        case PlayerDecisionOutputs::NO_DECISION:
            break;
        case PlayerDecisionOutputs::BUY_FIELD:
            break;
        case PlayerDecisionOutputs::MORTGAGE_FIELD:
            break;
        case PlayerDecisionOutputs::UNMORTGAGE_FIELD:
            break;
        case PlayerDecisionOutputs::BUY_HOUSE:
            break;
        case PlayerDecisionOutputs::SELL_HOUSE:
            break;
        case PlayerDecisionOutputs::BAIL_JAIL:
            break;
        case PlayerDecisionOutputs::JAIL_DICE_ROLL:
            break;
        case PlayerDecisionOutputs::USE_GET_OUT_OF_JAIL_CARD:
            break;
        case PlayerDecisionOutputs::THROW_DICE:
            break;
    }
}