//
// Created by adrwal on 11/3/24.
//

#ifndef GAME_H
#define GAME_H

#include "Board.h"


class Game {
public:
    explicit Game(Board& board)
        : board(board)
    {
    }
    bool isOver() const;

    void playTurn();
    void displayMenu(RoundState round_state) const;

private:
    Board& board;
};



#endif //GAME_H
