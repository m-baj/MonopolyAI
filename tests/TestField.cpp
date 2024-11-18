//
// Created by adrwal on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/Field.h"
#include "../src/Board.h"


TEST(TestField, getPlayersOnField)
{
    Board board;
    auto field0 = std::make_shared<Field>("", board);
    auto field1 = std::make_shared<Field>("", board);
    board.pushField(field0);
    board.pushField(field1);
    auto player = std::make_unique<ConsolePlayer>("", 1);
    player->setPositionIdx(0);
    board.pushPlayer(std::move(player));

    EXPECT_EQ(field0->getPlayersOnField()[0].value(), board.getPlayers()[0].get());
    EXPECT_EQ(field1->getPlayersOnField().empty(), true);
    EXPECT_EQ(field0->getPlayersOnField().size(), 1);
    EXPECT_EQ(field1->getPlayersOnField().size(), 0);
    board.movePlayer(1);
    EXPECT_EQ(field0->getPlayersOnField().empty(), true);
    EXPECT_EQ(field1->getPlayersOnField()[0].value(), board.getPlayers()[0].get());
}

TEST(TestField, getPlayersOnFieldManyPlayers)
{
    Board board;
    auto field0 = std::make_shared<Field>("", board);
    auto field1 = std::make_shared<Field>("", board);
    board.pushField(field0);
    board.pushField(field1);

    auto player0 = std::make_unique<ConsolePlayer>("", 1);
    auto player1 = std::make_unique<ConsolePlayer>("", 1);
    auto player2 = std::make_unique<ConsolePlayer>("", 1);
    auto player3 = std::make_unique<ConsolePlayer>("", 1);
    player0->setPositionIdx(0);
    player1->setPositionIdx(0);
    player2->setPositionIdx(1);
    player3->setPositionIdx(1);
    board.pushPlayer(std::move(player0));
    board.pushPlayer(std::move(player1));
    board.pushPlayer(std::move(player2));
    board.pushPlayer(std::move(player3));

    auto field0Players = field0->getPlayersOnField();
    auto field1Players = field1->getPlayersOnField();

    EXPECT_EQ(field0Players.size(), 2);
    EXPECT_EQ(field1Players.size(), 2);
    EXPECT_EQ(field0Players[0].value(), board.getPlayers()[0].get());
    EXPECT_EQ(field0Players[1].value(), board.getPlayers()[1].get());
    EXPECT_EQ(field1Players[0].value(), board.getPlayers()[2].get());
    EXPECT_EQ(field1Players[1].value(), board.getPlayers()[3].get());
    board.setCurrentPlayerIndex(0);

    board.movePlayer(1);
    field0Players = field0->getPlayersOnField();
    field1Players = field1->getPlayersOnField();
    EXPECT_EQ(field0Players.size(), 1);
    EXPECT_EQ(field1Players.size(), 3);
    EXPECT_EQ(field0Players[0].value(), board.getPlayers()[1].get());
    EXPECT_EQ(field1Players[0].value(), board.getPlayers()[0].get());
    EXPECT_EQ(field1Players[1].value(), board.getPlayers()[2].get());
    EXPECT_EQ(field1Players[2].value(), board.getPlayers()[3].get());
    board.setCurrentPlayerIndex(3);

    board.movePlayer(1);
    field0Players = field0->getPlayersOnField();
    field1Players = field1->getPlayersOnField();
    EXPECT_EQ(field0Players.size(), 2);
    EXPECT_EQ(field1Players.size(), 2);
    EXPECT_EQ(field0Players[0].value(), board.getPlayers()[1].get());
    EXPECT_EQ(field0Players[1].value(), board.getPlayers()[3].get());
    EXPECT_EQ(field1Players[0].value(), board.getPlayers()[0].get());
    EXPECT_EQ(field1Players[1].value(), board.getPlayers()[2].get());

}

TEST(TestField, getFieldIdx)
{
    Board board;
    auto field0 = std::make_shared<Field>("", board);
    auto field1 = std::make_shared<Field>("", board);
    auto field2 = std::make_shared<Field>("", board);
    auto field3 = std::make_shared<Field>("", board);
    board.pushField(field0);
    board.pushField(field1);
    board.pushField(field2);
    board.pushField(field3);

    EXPECT_EQ(field0->getFieldIdx(), 0);
    EXPECT_EQ(field1->getFieldIdx(), 1);
    EXPECT_EQ(field2->getFieldIdx(), 2);
    EXPECT_EQ(field3->getFieldIdx(), 3);
}