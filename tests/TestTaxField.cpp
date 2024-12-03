//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "gtest/gtest.h"
#include "../src/TaxField.h"
#include "../src/Board.h"

TEST(TestOnPlayerEnter, PlayerPaysToBank)
{
    Board board;
    auto taxField = std::make_shared<TaxField>("", board);
    auto player = std::make_unique<ConsolePlayer>("", 1000);
    board.pushField(taxField);
    board.pushPlayer(std::move(player));

    taxField->onPlayerEnter(board.getCurrentPlayer());
    EXPECT_EQ(board.getCurrentPlayer()->getMoney(), 800);
}
