//
// Created by adrwal on 11/3/24.
// Class containing the main game loop
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"


class Game final {
public:
    explicit Game(Board& board)
        : board(board) {};
    ~Game() = default;

    Board& getBoard() const;
    bool isOver() const;

    void play();
    void nextTurn();

private:
    Board& board;
};


#endif//GAME_H