//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "gtest/gtest.h"
#include "../src/Board.h"
#include "../src/Player.h"
#include "../src/Constants.h"
#include "../src/Fields/Property.h"

TEST(TestGetOwner, OwnerExists) {
    Board board;
    auto owner = std::make_unique<ConsolePlayer>("owner", 1000);
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
    auto player = std::make_unique<ConsolePlayer>("player", 1000);
    auto owner = std::make_unique<ConsolePlayer>("owner", 1000);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    property->setOwner(owner.get());
    board.pushField(property);
    board.pushPlayer(std::move(player));
    board.pushPlayer(std::move(owner));
    property->onPlayerEnter(board.getCurrentPlayer());
    EXPECT_EQ(board.getPlayers()[0]->getMoney(), 999);
    EXPECT_EQ(board.getPlayers()[1]->getMoney(), 1001);
}

// TEST(TestOnPlayerEnter, PlayerUnmortgagesProperty) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 100, Color::BROWN);
//     property->setOwner(player.get());
//     property->setMortgaged(true);
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[0];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Unmortgage");
//     choice.action();
//     EXPECT_FALSE(property->getIsMortgaged());
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), int(1000 - 1.1 * property->getMortgagePrice()));
// }
//
// TEST(TestOnPlayerEnter, PlayerBuysHouse) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[0];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Buy house");
//     choice.action();
//     EXPECT_EQ(property->getNumberOfHouses(), 1);
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1000 - HOUSE_PRICE);
// }
//
// TEST(TestOnPlayerEnter, PlayerCanBuyOrSellHouse) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     property->addHouse();
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choices = decision.value().getChoices();
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choices.size(), 2);
//     EXPECT_EQ(choices[0].description, "Buy house");
//     EXPECT_EQ(choices[1].description, "Sell house");
// }
//
// TEST(TestOnPlayerEnter, PlayerCanBuyHotelOrSellHouse) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     property->addHouse();
//     property->addHouse();
//     property->addHouse();
//     property->addHouse();
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choices = decision.value().getChoices();
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choices.size(), 2);
//     EXPECT_EQ(choices[0].description, "Sell house");
//     EXPECT_EQ(choices[1].description, "Buy hotel");
// }
//
// TEST(TestOnPlayerEnter, PlayerSellsHouse) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     property->addHouse();
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[1];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Sell house");
//     choice.action();
//     EXPECT_EQ(property->getNumberOfHouses(), 0);
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1000 + HOUSE_PRICE);
// }
//
// TEST(TestOnPlayerEnter, PlayerBuysHotel) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     property->addHouse();
//     property->addHouse();
//     property->addHouse();
//     property->addHouse();
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[1];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Buy hotel");
//     choice.action();
//     EXPECT_EQ(property->getNumberOfHouses(), 0);
//     EXPECT_TRUE(property->getHasHotel());
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1000 - HOTEL_PRICE);
// }
//
// TEST(TestOnPlayerEnter, PlayerSellsHotel) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     property->setOwner(player.get());
//     property->setHasHotel(true);
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[0];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Sell hotel");
//     choice.action();
//     EXPECT_FALSE(property->getHasHotel());
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1000 + HOTEL_PRICE);
// }
//
// TEST(TestOnPlayerEnter, PlayerBuysProperty) {
//     Board board;
//     auto player = std::make_unique<Player>("player", 1000);
//     auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
//     board.pushField(property);
//     board.pushPlayer(std::move(player));
//     auto decision = property->onPlayerEnter(board.getCurrentPlayer());
//     auto choice = decision.value().getChoices()[0];
//     EXPECT_TRUE(decision.has_value());
//     EXPECT_EQ(choice.description, "Buy property");
//     choice.action();
//     EXPECT_EQ(board.getPlayers()[0]->getMoney(), 1000 - 1);
//     EXPECT_EQ(property->getOwner(), board.getPlayers()[0].get());
//     EXPECT_EQ(board.getPlayers()[0]->getProperties().size(), 1);
// }