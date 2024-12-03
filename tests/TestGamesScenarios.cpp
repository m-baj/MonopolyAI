//
// Created by adrwal on 11/17/24.
//
#include <gtest/gtest.h>

#include "../src/Field.h"
#include "../src/Board.h"
#include "../src/BoardSetupper.h"
#include "../src/Game.h"


TEST(TestField, scenario0)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    auto player0 = std::make_unique<ConsolePlayer>("player0", 1000);
    auto player1 = std::make_unique<ConsolePlayer>("player1", 1000);
    auto player2 = std::make_unique<ConsolePlayer>("player2", 1000);
    auto player3 = std::make_unique<ConsolePlayer>("player3", 1000);

    board.pushPlayer(std::move(player0));
    board.pushPlayer(std::move(player1));
    board.pushPlayer(std::move(player2));
    board.pushPlayer(std::move(player3));

    // game.play();
}

