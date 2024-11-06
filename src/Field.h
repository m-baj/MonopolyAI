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

class Field {
public:
    explicit Field(const std::string& name, Board& board)
        : name(name), board(board)
    {
    }

    virtual ~Field() = default;
    virtual void onPlayerEnter(Player* player) {};

    std::string getName() const { return this->name; };
    std::vector<std::optional<Player*>> getPlayersOnField() const;
    int getFieldIdx() const;

protected:
    std::string name;
    Board& board;
};



#endif //FIELD_H
