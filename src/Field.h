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
     * Handles all actions that have to be done with player before he can provide any input.
     */
    virtual void onPlayerEnter(Player* player) { return std::nullopt; };

protected:
    std::string name;
    Board& board;
};



#endif //FIELD_H
