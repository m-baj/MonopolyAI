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
    auto player = std::make_unique<Player>("", 1);
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
