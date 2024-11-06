//
// Created by adrwal on 11/3/24.
//

#ifndef FIELD_H
#define FIELD_H
#include <memory>
#include <string>
#include <utility>


class Board;

class Field {
public:
    explicit Field(const std::string& name, Board& board)
        : name(name), board(board)
    {
    }

    virtual ~Field() = default;
    virtual void onPlayerEnter() = 0;

protected:
    std::string name;
    Board& board;
};



#endif //FIELD_H
