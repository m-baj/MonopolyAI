//
// Created by Maksymilian Baj on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/Board.h"
#include "../src/Fields/Trains.h"
#include <iostream>

TEST(TestCalculateRent, testCalculateRent) {
    Board board;
    auto owner = std::make_unique<ConsolePlayer>("owner_", 1000);
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

// TEST(TestTrainsOnPlayerEnter, PlayerPaysRent)
// {
//     Board board_;
//     auto owner_ = std::make_unique<ConsolePlayer>("owner_", 1000);
//     auto player = std::make_unique<ConsolePlayer>("player", 1000);
//     auto train = std::make_shared<Trains>("", board_, 100);
//     train->setOwner(owner_.get());
//     board_.pushField(train);
//     owner_->pushTrain(train);
//     board_.pushPlayer(std::move(owner_));
//     board_.pushPlayer(std::move(player));
//     auto decision = train->onPlayerEnter(board_.getPlayers()[1].get());
//     EXPECT_EQ(board_.getPlayers()[1]->getMoney(), 1000 - BASE_RENT_FOR_TRAIN);
//     EXPECT_EQ(board_.getPlayers()[0]->getMoney(), 1000 + BASE_RENT_FOR_TRAIN);
// }

// TEST(TestTrainsOnPlayerEnter, PlayerMayBuyTrain)
// {
//     Board board_;
//     auto player = std::make_unique<ConsolePlayer>("player", 1000);
//     auto train = std::make_shared<Trains>("", board_, 100);
//     board_.pushField(train);
//     board_.pushPlayer(std::move(player));
//     auto decision = train->onPlayerEnter(board_.getPlayers()[0].get());
//     EXPECT_EQ(decision.has_value(), true);
//     EXPECT_EQ(decision.value().getChoices().size(), 1);
//     EXPECT_EQ(decision.value().getChoices()[0].description, "Buy trains_");
// }
//
// TEST(TestTrainsOnPlayerEnter, PlayerBuysTrain)
// {
//     Board board_;
//     auto player = std::make_unique<ConsolePlayer>("player", 1000);
//     auto train = std::make_shared<Trains>("", board_, 100);
//     board_.pushField(train);
//     board_.pushPlayer(std::move(player));
//     auto decision = train->onPlayerEnter(board_.getPlayers()[0].get());
//     auto choice = decision.value().getChoices()[0];
//     EXPECT_EQ(decision.value().getChoices()[0].description, "Buy trains_");
//     choice.action();
//     EXPECT_EQ(board_.getPlayers()[0]->getMoney(), 1000 - 100);
//     EXPECT_EQ(board_.getPlayers()[0]->getTrains().size(), 1);
//     EXPECT_EQ(train->getOwner(), board_.getPlayers()[0].get());
// }