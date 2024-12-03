//
// Created by adrwal on 11/3/24.
// Class representing a field on the board_.
//

#ifndef FIELD_H
#define FIELD_H
#include <optional>
#include <string>
#include <vector>

#include "../Constants.h"
#include "../Player.h"

class Board;
/*
 * Base class for all fields_ on the board_.
 * Provides helper location-related methods.
 */
class Field {
public:
    explicit Field(const std::string& name, Board& board)
        : name_(name), board_(board) {};

    virtual ~Field() = default;

    std::string getName() const;
    std::vector<std::optional<Player*>> getPlayersOnField() const;
    int getFieldIdx() const;

    /*
     * Method called when player enters the field.
     * Executes all immediate actions.
     * In some cases will call DecisionSelector.requireSelection(). (e.g. when player is out of money_)
     */
    virtual void onPlayerEnter(Player* player) {};

    virtual std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const;
    bool canMortgageAnyField(Player* player) const;
    bool canUnmortgageAnyField(Player* player) const;
    bool canSellAnyHouse(Player* player) const;

protected:
    std::string name_;
    Board& board_;
};


#endif//FIELD_H
