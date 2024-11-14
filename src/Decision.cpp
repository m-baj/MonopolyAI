//
// Created by Maksymilian Baj on 13.11.2024.
//

#include "Decision.h"

std::vector<Decision::Choice> Decision::getChoices() const {
    return choices;
}

void Decision::addChoice(const Choice& choice) {
    choices.push_back(choice);
}
