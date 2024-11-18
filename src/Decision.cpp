//
// Created by Maksymilian Baj on 13.11.2024.
//

#include "Decision.h"

#include <iostream>

// std::vector<Decision::Choice> Decision::getChoices() const {
//     return choices;
// }
//
// void Decision::addChoice(const Choice& choice) {
//     choices.push_back(choice);
// }
//
// const Decision& ChoiceSelection::getDecision() const {
//     return this->decision;
// }
//
// const std::string& ChoiceSelection::getLabel() const {
//     return label;
// }
//
// void ConsoleChoiceSelection::requireSelection() {
//     int i = 1;
//     std::cout << getLabel() << std::endl;
//     for (const auto& choice : getDecision().getChoices()) {
//         std::cout << i << ". " << choice.description << std::endl;
//         i++;
//     }
//     int choice;
//     std::cin >> choice;
//     getDecision().getChoices()[choice - 1].action();
// }

void ConsoleDecisionSelector::requireSelection(const std::string& label,
                                               const std::vector<PlayerDecisionOutputs>&
                                               possibleDecisions)
{
    // TODO: Implement decision selection through console. All decisions in `possibleDecisions` should be handled here, as well as decisions following from them.
}
