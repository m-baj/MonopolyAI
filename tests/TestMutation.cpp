//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Mutation.h"

using namespace NEAT;
TEST(TestMutation, TestMutateEdge)
{
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::INPUT, 1));
    genotype.addNode(NodeInfo(NodeType::HIDDEN, 2));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 3));
    genotype.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype.addEdge(EdgeInfo(0, 3, 1.0, true, 3));

    HistoricalMarkings markings;
    markings.registerBaseMarkings(2, 1);

    Mutation mutation;
    mutation.mutateEdge(genotype, markings);

    EdgeInfo newEdge = genotype.getEdges()[genotype.getEdgesCount() - 1];
    EXPECT_EQ(genotype.getEdgesCount(), 5);
    EXPECT_EQ(newEdge.sourceIdx, 1);
    EXPECT_EQ(newEdge.destIdx, 3);
}

TEST(TestMutation, TestMutateEdgeFirstEdge) {
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 1));

    HistoricalMarkings markings;
    markings.registerBaseMarkings(1, 1);

    Mutation mutation;
    mutation.mutateEdge(genotype, markings);

    EdgeInfo newEdge = genotype.getEdges()[0];
    EXPECT_EQ(genotype.getEdgesCount(), 1);
    EXPECT_EQ(newEdge.sourceIdx, 0);
    EXPECT_EQ(newEdge.destIdx, 1);
    EXPECT_EQ(markings.getMarkings().size(), 1);
}

TEST(TestMutation, TestMutateNode) {
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 1));
    genotype.addEdge(EdgeInfo(0, 1, 1.0, true, 0));

    HistoricalMarkings markings;
    markings.registerBaseMarkings(1, 1);

    Mutation mutation;
    mutation.mutateNode(genotype, markings);
    EXPECT_EQ(genotype.getNodesCount(), 3);
    EXPECT_EQ(genotype.getEdgesCount(), 3);
    EdgeInfo oldEdge = genotype.getEdges()[0];
    EdgeInfo newEdge1 = genotype.getEdges()[1];
    EdgeInfo newEdge2 = genotype.getEdges()[2];
    EXPECT_EQ(oldEdge.isEnabled, false);
    EXPECT_EQ(newEdge1.sourceIdx, 0);
    EXPECT_EQ(newEdge1.destIdx, 2);
    EXPECT_EQ(newEdge2.sourceIdx, 2);
    EXPECT_EQ(newEdge2.destIdx, 1);
}
TEST(TestMutation, TestMutateEnable) {
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 1));
    genotype.addEdge(EdgeInfo(0, 1, 1.0, false, 0));

    Mutation mutation;
    EdgeInfo& edge = genotype.getEdge(0);
    EXPECT_FALSE(edge.isEnabled);
    mutation.mutateEnable(genotype);
    EXPECT_EQ(genotype.getEdgesCount(), 1);
    EXPECT_TRUE(edge.isEnabled);
}

TEST(TestMutation, TestMutateDisable) {
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 1));
    genotype.addEdge(EdgeInfo(0, 1, 1.0, true, 0));

    Mutation mutation;
    EdgeInfo& edge = genotype.getEdge(0);
    EXPECT_TRUE(edge.isEnabled);
    mutation.mutateDisable(genotype);
    EXPECT_EQ(genotype.getEdgesCount(), 1);
    EXPECT_FALSE(edge.isEnabled);
}

TEST(TestMutation, TestMutateWeight) {
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 1));
    genotype.addEdge(EdgeInfo(0, 1, 1.0, true, 0));

    HistoricalMarkings markings;
    markings.registerBaseMarkings(1, 1);

    Mutation mutation;
    EdgeInfo& edge = genotype.getEdge(0);
    double oldWeight = edge.weight;
    mutation.mutateWeight(genotype);
    EXPECT_EQ(genotype.getEdgesCount(), 1);
    EXPECT_NE(oldWeight, edge.weight);
}

