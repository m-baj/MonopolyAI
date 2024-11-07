//
// Created by Maksymilian Baj on 07.11.2024.
//

#include "gtest/gtest.h"
#include "../src/Bank.h"

TEST(TestBank, payMoneyTo)
{
    Bank bank;
    auto player = std::make_shared<Player>("Player", 1000);
    bank.payMoneyTo(player.get(), 300);
    EXPECT_EQ(player->getMoney(), 1300);
}
