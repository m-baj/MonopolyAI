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

TEST(TestGame, getDecisionsOnFieldUnmortgageField)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));

    board.setRollDiceSeed(3);
    std::stringstream myStringStream = std::stringstream("td\nbf\nmo\n0\n-");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    game.nextTurn();

    board.movePlayer(3);
    auto decisions = board.getSteppedOnField()->getFieldDecisions(board.getCurrentPlayer());
    EXPECT_EQ(decisions.size(), 3);
    EXPECT_THAT(decisions, ::testing::UnorderedElementsAre(PlayerDecisionOutputs::NO_DECISION, PlayerDecisionOutputs::BUY_FIELD, PlayerDecisionOutputs::UNMORTGAGE_FIELD));
}

TEST(TestGame, getDecisionsOnFieldUnmortgageMortgagePropertyWhenMoreThan1PropertiesAreOwned)
{
    Board board;
    Game game(board);
    BoardSetupCreator::createClassicBoard(board);
    board.pushPlayer(std::make_unique<ConsolePlayer>("player0", 1000, board));

    board.setRollDiceSeed(3);
    std::stringstream myStringStream = std::stringstream("td\nbf\nmo\n0\n-\ntd\nbf\n-");
    ConsoleDecisionSelector::in_stream = &myStringStream;
    game.nextTurn();
    auto player = board.getPlayers()[0].get();
    EXPECT_EQ(player->getMoney(), 970);
    EXPECT_EQ(player->getProperties().size(), 1);
    EXPECT_EQ(player->getProperties()[0].get()->getIsMortgaged(), true);
    game.nextTurn();
    EXPECT_EQ(player->getMoney(), 870);
    EXPECT_EQ(player->getProperties().size(), 2);
    EXPECT_EQ(player->getProperties()[0].get()->getIsMortgaged(), true);
    EXPECT_EQ(player->getProperties()[1].get()->getIsMortgaged(), false);

    board.movePlayer(1);
    auto decisions = board.getSteppedOnField()->getFieldDecisions(board.getCurrentPlayer());
    EXPECT_EQ(decisions.size(), 3);
    EXPECT_THAT(decisions, ::testing::UnorderedElementsAre(PlayerDecisionOutputs::NO_DECISION, PlayerDecisionOutputs::UNMORTGAGE_FIELD, PlayerDecisionOutputs::MORTGAGE_FIELD));
}