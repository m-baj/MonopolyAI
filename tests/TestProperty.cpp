//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "gtest/gtest.h"
#include "../src/Board.h"

TEST(TestGetOwner, OwnerExists) {
    Board board;
    Player player("Player", 1000);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    player.pushOwnable(property);
    board.pushPlayer(std::make_unique<Player>(player));
    EXPECT_EQ(property->getOwner().value(), board.getPlayers()[0].get());
}

TEST(TestGetOwner, testOwnerDoesNotExist) {
    Board board;
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    EXPECT_EQ(property->getOwner(), std::nullopt);
}

TEST(TestOnPlayerEnter, PlayerPaysRent) {
    Board board;
    Player player1("Player1", 1000);
    Player player2("Player2", 1000);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    player1.pushOwnable(property);
    board.pushPlayer(std::make_unique<Player>(player1));
    board.pushPlayer(std::make_unique<Player>(player2));
    property->onPlayerEnter(board.getPlayers()[1].get());
    EXPECT_EQ(board.getPlayers()[1]->getMoney(), 999);
    EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1001);
}