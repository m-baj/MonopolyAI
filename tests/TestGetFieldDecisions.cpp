//
// Created by adrwal on 1/19/25.
//
//
// Created by adrwal on 11/17/24.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>

#include "../src/Fields/Field.h"
#include "../src/Board.h"
#include "../src/BoardSetupper.h"
#include "../src/Game.h"
#include "../src/Decision/ConsoleDecisionSelector.h"
#include "../src/Fields/Property.h"

TEST(TestGame, getDecisionsOnFieldReadyToBuy)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player1", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player2", 1000, board));
    board.pushPlayer(std::make_unique<ConsolePlayer>("player3", 1000, board));

    board.movePlayer(3);
    auto decisions = board.getSteppedOnField()->getFieldDecisions(board.getCurrentPlayer());
    EXPECT_EQ(decisions.size(), 2);
    EXPECT_THAT(decisions, ::testing::UnorderedElementsAre(PlayerDecisionOutputs::BUY_FIELD, PlayerDecisionOutputs::NO_DECISION));
}

TEST(TestGame, getDecisionsOnFieldCannotBuyFieldWhenItsBought)
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

    board.movePlayer(3);
    auto decisions = board.getSteppedOnField()->getFieldDecisions(board.getCurrentPlayer());
    EXPECT_EQ(decisions.size(), 1);
    EXPECT_THAT(decisions, ::testing::UnorderedElementsAre(PlayerDecisionOutputs::NO_DECISION));
}

TEST(TestGame, getDecisionsOnFieldMortgageField)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));

    board.setRollDiceSeed(3);
    std::stringstream myStringStream = std::stringstream("td\nbf\n-");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    game.nextTurn();

    board.movePlayer(3);
    auto decisions = board.getSteppedOnField()->getFieldDecisions(board.getCurrentPlayer());
    EXPECT_EQ(decisions.size(), 3);
    EXPECT_THAT(decisions, ::testing::UnorderedElementsAre(PlayerDecisionOutputs::NO_DECISION, PlayerDecisionOutputs::BUY_FIELD, PlayerDecisionOutputs::MORTGAGE_FIELD));
}
