//
// Created by Maksymilian Baj on 13.11.2024.
//

#ifndef MONOPOLYAI_DECISION_H
#define MONOPOLYAI_DECISION_H

#include <string>
#include <functional>

class Decision {
public:
    struct Choice
    {
        std::string description;
        std::function<void()> action;
    };

    Decision() = default;
    std::vector<Choice> getChoices() const;
    void addChoice(const Choice& choice);

private:
    std::vector<Choice> choices = {};
};


#endif //MONOPOLYAI_DECISION_H
