//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Genotype.h"

TEST(TestGenotype, TestGetInputAndOutputNodesFromParent) {
    NEAT::Genotype parent;
    parent.addNode(NEAT::NodeInfo(NEAT::NodeType::INPUT, 0));
    parent.addNode(NEAT::NodeInfo(NEAT::NodeType::INPUT, 1));
    parent.addNode(NEAT::NodeInfo(NEAT::NodeType::HIDDEN, 2));
    parent.addNode(NEAT::NodeInfo(NEAT::NodeType::OUTPUT, 3));

    NEAT::Genotype child;
    child.getInputAndOutputNodesFromParent(parent);

    EXPECT_EQ(child.getNodesCount(), 3);
    EXPECT_EQ(child.getNodes()[0].index, 0);
    EXPECT_EQ(child.getNodes()[1].index, 1);
    EXPECT_EQ(child.getNodes()[2].index, 3);
}

TEST(TestGenotype, TestUpdateHiddenNodes) {
    NEAT::Genotype genotype;
    genotype.addNode(NEAT::NodeInfo(NEAT::NodeType::INPUT, 0));
    genotype.addNode(NEAT::NodeInfo(NEAT::NodeType::INPUT, 1));
    genotype.addNode(NEAT::NodeInfo(NEAT::NodeType::OUTPUT, 3));
    genotype.addEdge(NEAT::EdgeInfo(0, 2, 1.0, true, 0));
    genotype.addEdge(NEAT::EdgeInfo(1, 2, 1.0, true, 1));
    genotype.addEdge(NEAT::EdgeInfo(2, 3, 1.0, true, 2));

    EXPECT_EQ(genotype.getNodesCount(), 3);
    EXPECT_EQ(genotype.getEdgesCount(), 3);
    genotype.updateHiddenNodes();

    EXPECT_EQ(genotype.getNodesCount(), 4);
    EXPECT_EQ(genotype.getEdgesCount(), 3);
}