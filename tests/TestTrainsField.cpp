//
// Created by Maksymilian Baj on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/Fields/Trains.h"
#include "../src/Board.h"
#include <iostream>

TEST(TestCalculateRent, testCalculateRent)
{
    Board board;
    auto owner = std::make_unique<ConsolePlayer>("owner", 1000);
    auto train1 = std::make_shared<Trains>("", board, 100);
    auto train2 = std::make_shared<Trains>("", board, 100);
    train1->setOwner(owner.get());
    train2->setOwner(owner.get());
    board.pushField(train1);
    board.pushField(train2);
    owner->pushTrain(train1);
    owner->pushTrain(train2);
    board.pushPlayer(std::move(owner));
    EXPECT_EQ(board.getPlayers()[0]->getNumberOfTrains(), 2);
    int rent = train1->calculateRentPrice();
    EXPECT_EQ(rent, BASE_RENT_FOR_TRAIN * 2);
}
