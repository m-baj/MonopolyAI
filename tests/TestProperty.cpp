//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "gtest/gtest.h"
#include "../src/Board.h"

TEST(TestGetOwner, OwnerExists) {
    Board board;
    auto owner = std::make_unique<Player>("owner", 1000);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    property->setOwner(owner.get());
    EXPECT_EQ(property->getOwner(), owner.get());
}

TEST(TestGetOwner, testOwnerDoesNotExist) {
    Board board;
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    EXPECT_EQ(property->getOwner(), std::nullopt);
}

TEST(TestOnPlayerEnter, PlayerPaysRent) {
    Board board;
    auto player = std::make_unique<Player>("player", 1000);
    auto owner = std::make_unique<Player>("owner", 1000);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    property->setOwner(owner.get());
    board.pushField(property);
    board.pushPlayer(std::move(player));
    board.pushPlayer(std::move(owner));
    property->onPlayerEnter(board.getCurrentPlayer());
    EXPECT_EQ(board.getPlayers()[0]->getMoney(), 999);
    EXPECT_EQ(board.getPlayers()[1]->getMoney(), 1001);
}