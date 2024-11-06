//
// Created by adrwal on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/CardField.h"
#include "../src/Board.h"

TEST(TestCardField, CorrectInit)
{
    Board board;
    std::shared_ptr<CardField> cardField = std::make_shared<CardField>("CardField", board);
    board.pushField(cardField);
    EXPECT_EQ(1, 1);
}