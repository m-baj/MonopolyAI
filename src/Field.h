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

    virtual void onPlayerEnter(Player* player) {};

protected:
    std::string name;
    Board& board;
};



#endif //FIELD_H
