//
// Created by adrwal on 11/3/24.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"


class Game final
{
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

// /*
//  * GameCli class is CLI frontend for the game engine.
//  * It is responsible for mapping user input to immediate state-changing actions performed by Board.
//  */
// class GameCli : public Game {
// public:
//     explicit GameCli(Board& board)
//         : Game(board) {};
//
//     bool isOver() const override;
//     void displayMenu(RoundState round_state) const;
//     void drawBoard() const;
//     static void addClassicMonopolyFields(Board& board);
//
//     // std::unique_ptr<ChoiceSelection> createChoiceSelection(const Decision& decision, const std::string& label) const override;
//     void play() override;
// };
//
// class GameNonInteractive
// {
// public:
//     explicit GameNonInteractive(Board& board)
//         : board(board) {};
//
//     bool isOver() const;
//     void play();
//
// private:
//     Board& board;
// };


#endif //GAME_H