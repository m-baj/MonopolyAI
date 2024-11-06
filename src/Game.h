//
// Created by adrwal on 11/3/24.
//

#ifndef GAME_H
#define GAME_H

#include "Board.h"

/*
 * Game class is CLI frontend for the game engine.
 * It is responsible for mapping user input to immediate state-changing actions performed by Board.
 */
class Game {
public:
    explicit Game(Board& board)
        : board(board) {};

    bool isOver() const;
    void displayMenu(RoundState round_state) const;
    void drawBoard() const;

    void playTurn();

private:
    Board& board;
};



#endif //GAME_H
