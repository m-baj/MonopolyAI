//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Crossover.h"

using namespace NEAT;

TEST(TestCrossover, TestChooseOneMatchingEdge) {
    EdgeInfo first(0, 1, 1.0, true, 0);
    EdgeInfo second(0, 1, 1.0, false, 1);

    EXPECT_EQ(&chooseOneMatchingEdge(first, second), &first);
}

TEST(TestCrossover, TestClassifyEdgesAllMatching) {
    Edges firstEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, true, 1),
            EdgeInfo(2, 3, 1.0, true, 2),
    };
    Edges secondEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, false, 1),
            EdgeInfo(2, 3, 1.0, true, 2),
    };

    auto [matchingEdges, disjointEdges, excessEdges] = classifyEdges(firstEdges, secondEdges);

    EXPECT_EQ(matchingEdges.size(), 3);
    EXPECT_EQ(disjointEdges.size(), 0);
    EXPECT_EQ(excessEdges.size(), 0);
}

TEST(TestCrossover, TestClassifyEdgesOneDisjoint) {
    Edges firstEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, true, 1),
            EdgeInfo(2, 3, 1.0, true, 2),
    };
    Edges secondEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(2, 3, 1.0, true, 2),
    };

    auto [matchingEdges, disjointEdges, excessEdges] = classifyEdges(firstEdges, secondEdges);

    EXPECT_EQ(matchingEdges.size(), 2);
    EXPECT_EQ(disjointEdges.size(), 1);
    EXPECT_EQ(excessEdges.size(), 0);
    EXPECT_EQ(disjointEdges[0].sourceIdx, 1);
}

TEST(TestCrossover, TestClassifyEdgesOneExcess) {
    Edges firstEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, true, 1),
    };
    Edges secondEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, true, 1),
            EdgeInfo(2, 3, 1.0, true, 2),
    };

    auto [matchingEdges, disjointEdges, excessEdges] = classifyEdges(firstEdges, secondEdges);

    EXPECT_EQ(matchingEdges.size(), 2);
    EXPECT_EQ(disjointEdges.size(), 0);
    EXPECT_EQ(excessEdges.size(), 1);
    EXPECT_EQ(excessEdges[0].sourceIdx, 2);
}

TEST(TestCrossover, TestClassifyEdgesOneExcessOneDisjoint) {
    Edges firstEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(1, 2, 1.0, true, 1),
            EdgeInfo(2, 3, 1.0, true, 2),
    };
    Edges secondEdges = {
            EdgeInfo(0, 1, 1.0, true, 0),
            EdgeInfo(2, 3, 1.0, true, 2),
            EdgeInfo(3, 4, 1.0, true, 3),
    };

    auto [matchingEdges, disjointEdges, excessEdges] = classifyEdges(firstEdges, secondEdges);

    EXPECT_EQ(matchingEdges.size(), 2);
    EXPECT_EQ(disjointEdges.size(), 1);
    EXPECT_EQ(excessEdges.size(), 1);
    EXPECT_EQ(disjointEdges[0].sourceIdx, 1);
    EXPECT_EQ(excessEdges[0].sourceIdx, 3);
}

TEST(TestCrossover, TestCrossoverNoChanges) {
    Genotype parent1;
    parent1.addNode(NodeInfo(NodeType::INPUT, 0));
    parent1.addNode(NodeInfo(NodeType::INPUT, 1));
    parent1.addNode(NodeInfo(NodeType::HIDDEN, 2));
    parent1.addNode(NodeInfo(NodeType::OUTPUT, 3));
    parent1.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    parent1.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    parent1.addEdge(EdgeInfo(2, 3, 1.0, true, 2));

    Genotype parent2;
    parent2.addNode(NodeInfo(NodeType::INPUT, 0));
    parent2.addNode(NodeInfo(NodeType::INPUT, 1));
    parent2.addNode(NodeInfo(NodeType::HIDDEN, 2));
    parent2.addNode(NodeInfo(NodeType::OUTPUT, 3));
    parent2.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    parent2.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    parent2.addEdge(EdgeInfo(2, 3, 1.0, true, 2));

    Genotype child = crossover(parent1, parent2);

    EXPECT_EQ(child.getNodesCount(), 4);
    EXPECT_EQ(child.getEdgesCount(), 3);
}

TEST(TestCrossover, TestCrossover) {
    Genotype parent1;
    parent1.addNode(NodeInfo(NodeType::INPUT, 0));
    parent1.addNode(NodeInfo(NodeType::INPUT, 1));
    parent1.addNode(NodeInfo(NodeType::INPUT, 2));
    parent1.addNode(NodeInfo(NodeType::HIDDEN, 3));
    parent1.addNode(NodeInfo(NodeType::OUTPUT, 4));
    parent1.addEdge(EdgeInfo(0, 3, 1.0, true, 1));
    parent1.addEdge(EdgeInfo(1, 3, 1.0, true, 2));
    parent1.addEdge(EdgeInfo(1, 4, 1.0, false, 4));
    parent1.addEdge(EdgeInfo(2, 4, 1.0, true, 5));
    parent1.addEdge(EdgeInfo(3, 4, 1.0, true, 6));

    Genotype parent2;
    parent2.addNode(NodeInfo(NodeType::INPUT, 0));
    parent2.addNode(NodeInfo(NodeType::INPUT, 1));
    parent2.addNode(NodeInfo(NodeType::HIDDEN, 2));
    parent2.addNode(NodeInfo(NodeType::HIDDEN, 5));
    parent2.addNode(NodeInfo(NodeType::HIDDEN, 3));
    parent2.addNode(NodeInfo(NodeType::OUTPUT, 4));
    parent2.addEdge(EdgeInfo(0, 3, 1.0, false, 1));
    parent2.addEdge(EdgeInfo(1, 3, 1.0, true, 2));
    parent2.addEdge(EdgeInfo(2, 3, 1.0, true, 3));
    parent2.addEdge(EdgeInfo(1, 4, 1.0, false, 4));
    parent2.addEdge(EdgeInfo(3, 4, 1.0, true, 6));
    parent2.addEdge(EdgeInfo(0, 5, 1.0, true, 7));
    parent2.addEdge(EdgeInfo(5, 3, 1.0, true, 8));

    Genotype child = crossover(parent1, parent2);
    EXPECT_EQ(child.getEdgesCount(), 8);
    EXPECT_EQ(child.getNodesCount(), 6);
}