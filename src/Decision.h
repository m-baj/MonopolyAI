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

class ChoiceSelection {
public:
    virtual ~ChoiceSelection() = default;
    explicit ChoiceSelection(const Decision& decision, const std::string& label)
        : decision(decision), label(label) {};

    const Decision& getDecision() const;
    const std::string& getLabel() const;

    virtual void requireSelection() = 0;

private:
    Decision decision;
    std::string label;
};

class ConsoleChoiceSelection final : public ChoiceSelection {
public:
    ConsoleChoiceSelection(const Decision& decision, const std::string& label)
        : ChoiceSelection(decision, label) {};

    void requireSelection() override;
};


#endif //MONOPOLYAI_DECISION_H
