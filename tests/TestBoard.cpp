//
// Created by adrwal on 11/6/24.
//

#include <gtest/gtest.h>

#include "../src/Board.h"
#include "../src/CardField.h"

TEST(TestBoard, CorrectInit)
{
    Board board;
    EXPECT_EQ(1, 1);
}

TEST(TestBoard, InitAllFields)
{
    Board board;
    board.push_field(std::make_shared<Field>("START", board));
    board.push_field(std::make_shared<Property>("MEDITER-RANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
    board.push_field(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.push_field(std::make_shared<Property>("BALTIC AVENUE", board, 60, 10, 30, Color::BROWN));
    EXPECT_EQ(1, 1);
}
