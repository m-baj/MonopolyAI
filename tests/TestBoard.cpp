//
// Created by adrwal on 11/6/24.
//

#include <gtest/gtest.h>

#include "../src/Board.h"


class TestGetNewPosition : public ::testing::TestWithParam<std::tuple<
    int,
    int,
    int,
    int>
>{};

TEST_P(TestGetNewPosition, getNewPosition)
{
    Board board;
    auto [boardSize, prevIdx, steps, expectedIdx] = GetParam();
    for (int i = 0; i < boardSize; i++)
    {
        board.pushField(std::make_shared<Field>("", board));
    }
    auto player = std::make_unique<ConsolePlayer>("", 1);
    player.get()->setPositionIdx(prevIdx);
    board.pushPlayer(std::move(player));
    board.setCurrentPlayerIndex(0);

    EXPECT_EQ(board.getNewPosition(board.getCurrentPlayer(), steps), expectedIdx);

}

INSTANTIATE_TEST_CASE_P(
    GetNewPositionCases,
    TestGetNewPosition,
    ::testing::Values(
        std::make_tuple(40, 0, 1, 1),
        std::make_tuple(40, 39, 1, 0),
        std::make_tuple(40, 10, 10, 20)
    )
);

class TestWillMoveCrossStart : public ::testing::TestWithParam<std::tuple<
    int,
    int,
    int,
    bool>
>{};
TEST_P(TestWillMoveCrossStart, willMoveCrossStart)
{
    Board board;
    auto [boardSize, prevIdx, steps, expected] = GetParam();
    for (int i = 0; i < boardSize; i++)
    {
        board.pushField(std::make_shared<Field>("", board));
    }
    auto player = std::make_unique<ConsolePlayer>("", 1);
    player.get()->setPositionIdx(prevIdx);
    board.pushPlayer(std::move(player));
    board.setCurrentPlayerIndex(0);

    EXPECT_EQ(board.willMoveCrossStart(board.getCurrentPlayer(), steps), expected);
}

INSTANTIATE_TEST_CASE_P(
    WillMoveCrossStartCases,
    TestWillMoveCrossStart,
    ::testing::Values(
        std::make_tuple(40, 0, 1, false),
        std::make_tuple(40, 39, 1, true),
        std::make_tuple(40, 10, 10, false)
    )
);
