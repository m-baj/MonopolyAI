//
// Created by adrwal on 11/3/24.
//

#ifndef FIELD_H
#define FIELD_H
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "Board.h"
#include "Decision.h"

class Player;
class Board;

/*
 * Base class for all fields on the board.
 * Provides helper location-related methods.
 */
class Field {
public:
    explicit Field(const std::string& name, Board& board)
        : name(name), board(board) {};

    virtual ~Field() = default;

    std::string getName() const;
    std::vector<std::optional<Player*>> getPlayersOnField() const;
    int getFieldIdx() const;

    /*
     * Method called when player enters the field.
     * Executes all immediate actions.
     * Returns decision that can later be made by player.
     * In some cases, need to prompt player decision immediately. (e.g. when player is out of money)
     */
    virtual std::vector<PlayerDecisionOutputs> onPlayerEnter(Player* player)
    {
        return {
            PlayerDecisionOutputs::THROW_DICE,
            PlayerDecisionOutputs::MORTGAGE_FIELD,
            PlayerDecisionOutputs::UNMORTGAGE_FIELD
        };
    };

protected:
    std::string name;
    Board& board;
};



#endif //FIELD_H
