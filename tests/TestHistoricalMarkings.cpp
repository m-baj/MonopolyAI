//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/HistoricalMarkings.h"

using namespace NEAT;

TEST(TestHistoricalMarkings, TestRegisterBaseMarkings)
{
    HistoricalMarkings markings;
    markings.registerBaseMarkings(2, 1);

    EXPECT_EQ(markings.getMarkings().size(), 2);
    EXPECT_EQ(markings.getMarkings()[0].innovation, 0);
    EXPECT_EQ(markings.getMarkings()[1].innovation, 1);
    EXPECT_EQ(markings.getMarkings()[0].sourceIdx, 0);
    EXPECT_EQ(markings.getMarkings()[0].destIdx, 2);
    EXPECT_EQ(markings.getMarkings()[1].sourceIdx, 1);
    EXPECT_EQ(markings.getMarkings()[1].destIdx, 2);
}

TEST(TestHistoricalMarkings, TestRegisterMarkingAlreadyExists)
{
    HistoricalMarkings markings;
    markings.registerBaseMarkings(2, 1);

    EdgeInfo edge(0, 2, 1.0, true, 0);
    int innovation = markings.registerMarking(edge);

    EXPECT_EQ(innovation, 0);
    EXPECT_EQ(markings.getMarkings().size(), 2);
    EXPECT_EQ(markings.getMarkings()[0].innovation, 0);
    EXPECT_EQ(markings.getMarkings()[0].sourceIdx, 0);
    EXPECT_EQ(markings.getMarkings()[0].destIdx, 2);
}

TEST(TestHistoricalMarkings, TestRegisterMarkingNewMarking)
{
    HistoricalMarkings markings;
    markings.registerBaseMarkings(2, 1);

    EdgeInfo edge(0, 3, 1.0, true, 0);
    int innovation = markings.registerMarking(edge);

    EXPECT_EQ(innovation, 2);
    EXPECT_EQ(markings.getMarkings().size(), 3);
    EXPECT_EQ(markings.getMarkings()[2].innovation, 2);
    EXPECT_EQ(markings.getMarkings()[2].sourceIdx, 0);
    EXPECT_EQ(markings.getMarkings()[2].destIdx, 3);
}