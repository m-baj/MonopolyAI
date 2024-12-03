//
// Created by Maksymilian Baj on 13.11.2024.
//

#include "Decision.h"

#include <iostream>

std::istream* ConsoleDecisionSelector::in_stream = &std::cin;
void ConsoleDecisionSelectorHelpers::printDecisions(const std::vector<PlayerDecisionOutputs>& possibleDecisions)
{
    for (auto decision : possibleDecisions)
    {
        std::cout << DECISION_SELECT_LABEL.at(decision) << std::endl;
    }
}

std::string ConsoleDecisionSelectorHelpers::receiveInput(std::istream& in)
{
    std::cout << "Enter decision: ";
    std::string decision;
    in >> decision;
    return decision;
}


void ConsoleDecisionSelector::requireSelection(const std::string& label,
                                               const std::vector<PlayerDecisionOutputs>&
                                               possibleDecisions)
{
    // TODO: Implement decision selection through console. All decisions in `possibleDecisions` should be handled here, as well as decisions following from them.
    ConsoleDecisionSelectorHelpers::printDecisions(possibleDecisions);
    std::cout << "Enter decision: ";
    std::string decision;
    *ConsoleDecisionSelector::in_stream >> decision;
}
