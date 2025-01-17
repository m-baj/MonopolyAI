#include <iostream>

#include "src/Board.h"
#include "src/BoardSetupper.h"
#include "src/Game.h"


int main()
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player1", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player2", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player3", 1000));

    game.play();

    return 0;
}

