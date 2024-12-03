//
// Created by adrwal on 11/17/24.
//
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "../src/Field.h"
#include "../src/Board.h"
#include "../src/BoardSetupper.h"
#include "../src/Game.h"
#include "../src/Decision/ConsoleDecisionSelector.h"

TEST(TestField, scenario0)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player1", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player2", 1000));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player3", 1000));

    std::stringstream myStringStream = std::stringstream("td");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    // game.nextTurn();
    // game.play();
}

