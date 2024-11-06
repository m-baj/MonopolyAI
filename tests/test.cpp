//
// Created by Maksymilian Baj on 04.11.2024.
//
#include <gtest/gtest.h>

#include "../src/Property.h"

TEST(Test, test)
{
    EXPECT_EQ(1, 1);
}

TEST(PropetyTest, CorectInit)
{
    Property property("Test", 100, 10, 50, Color::BROWN);
    std::cout << "property.name" << std::endl;
    EXPECT_EQ(1,1);
}