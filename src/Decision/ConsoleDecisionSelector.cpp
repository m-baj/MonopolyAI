//
// Created by adrwal on 12/3/24.
//

#include "ConsoleDecisionSelector.h"

#include <iostream>
#include <algorithm>

#include "FieldBuyVisitor.h"
#include "../Board.h"
#include "../Player.h"
#include "../Fields/OwnableField.h"
#include "../Fields/Property.h"

std::istream* ConsoleDecisionSelector::in_stream = &std::cin;
void ConsoleDecisionSelector::printDecisions(const std::vector<PlayerDecisionOutputs>& possibleDecisions) const
{
    for (auto decision : possibleDecisions)
    {
        std::cout << DECISION_SELECT_LABEL.at(decision) << std::endl;
    }
}

PlayerDecisionOutputs ConsoleDecisionSelector::receiveInput(std::istream& in, const std::vector<PlayerDecisionOutputs>& possibleDecisions) const
{
    std::string decision;
    std::map<std::string, PlayerDecisionOutputs>::const_iterator decision_enum;

    do
    {
        std::cout << "Enter decision ('pb' to print board, 'pi' for player info): ";
        in >> decision;
        decision_enum = STRING_TO_DECISION.find(decision);
        if (decision == "pb")
        {
            this->printBoard();
            this->printDecisions(possibleDecisions);
            continue;
        }
        if (decision == "pi")
        {
            this->printPlayersInfo();
            this->printDecisions(possibleDecisions);
            continue;
        }
        if (decision_enum == STRING_TO_DECISION.end() || std::ranges::find(possibleDecisions, decision_enum->second) == possibleDecisions.end())
        {
            std::cout << "Invalid decision. Please try again." << std::endl;
        }
    } while (decision_enum == STRING_TO_DECISION.end() || std::ranges::find(possibleDecisions, decision_enum->second) == possibleDecisions.end());

    return decision_enum->second;
}

void ConsoleDecisionSelector::printBoard() const
{
    for (int i = 0; i < player_.getBoard().getFields().size(); i++)
    {
        std::cout << i+1 << ": ";
        auto& field = player_.getBoard().getFields()[i];

        std::cout << "(" << field->getName() << ") ";
        auto players = field->getPlayersOnField();
        std::cout << "[ ";
        for (auto& player : players)
        {
            if(player.has_value())
            {
                std::cout << player.value()->getName() << " ";
            }
        }
        std::cout << "] " << std::endl;
    }
}

size_t ConsoleDecisionSelector::receiveListIndexInput(std::istream& in, size_t listSize) const
{
    int decision;
    in >> decision;
    while (decision < 0 || decision >= listSize)
    {
        std::cout << "Invalid decision. Please try again." << std::endl;
        in >> decision;
    }
    return decision;
}

void ConsoleDecisionSelector::printPlayersInfo() const
{
    for (const auto& player : player_.getBoard().getPlayers())
    {
        std::cout << player->getName() << " has " << player->getMoney() << " money" << std::endl;
    }
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

    this->printDecisions(possibleDecisions);
    PlayerDecisionOutputs decision = this->receiveInput(*this->in_stream, possibleDecisions);
    player_.saveTurnDecision(decision);

    switch (decision)
    {
        case PlayerDecisionOutputs::NO_DECISION:
            break;
        case PlayerDecisionOutputs::BUY_FIELD:
            {
                FieldBuyVisitor visitor;
                player_.getBoard().getSteppedOnField()->accept(visitor);
                break;
            }
        case PlayerDecisionOutputs::MORTGAGE_FIELD:
            {
                std::vector<Property*> mortgagableProperties;
                for (auto& field : player_.getProperties())
                {
                    if (field->getOwner() == &player_ && !field->getIsMortgaged())
                    {
                        mortgagableProperties.push_back(field.get());
                    }
                }
                int i = 0;
                for (const auto& field : mortgagableProperties)
                {
                    std::cout << i++ << ": " << field->getName() << std::endl;
                }
                std::cout << "Which field do you want to mortgage?: " << std::endl;
                int decision = this->receiveListIndexInput(*this->in_stream, mortgagableProperties.size());
                std::cout << "Mortgaging " << mortgagableProperties[decision]->getName() << std::endl;
                mortgagableProperties[decision]->mortgage();
                break;
            }
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
