//
// Created by adrwal on 11/17/24.
//
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "../src/Fields/Field.h"
#include "../src/Board.h"
#include "../src/BoardSetupper.h"
#include "../src/Game.h"
#include "../src/Decision/ConsoleDecisionSelector.h"
#include "../src/Fields/Property.h"

TEST(TestField, scenario0)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player1", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player2", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player3", 1000, board));

    std::stringstream myStringStream = std::stringstream("td\n-");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    game.nextTurn();

    EXPECT_EQ(board.getCurrentPlayer(), board.getPlayers()[1].get());
    EXPECT_EQ(board.getPlayers()[0]->getMadeTurnDecisions().size(), 0);
}

TEST(TestGame, scenarioBuyField)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player1", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player2", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player3", 1000, board));

    board.setRollDiceSeed(3);
    std::stringstream myStringStream = std::stringstream("td\nbf\n-");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    game.nextTurn();
    EXPECT_EQ(board.getPlayers()[0].get()->getProperties()[0].get()->getName(), board.getFields()[3].get()->getName());
    EXPECT_EQ(board.getPlayers()[0].get()->getMoney(), 940);
}

