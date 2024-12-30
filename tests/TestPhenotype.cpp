//
// Created by Maksymilian Baj on 30.12.2024.
//

#include <gtest/gtest.h>
#include "../src/neat/Phenotype.h"

using namespace NEAT;

TEST(TestPhenotype, TestCreatePhenotypeFromGenotype)
{

    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::INPUT, 1));
    genotype.addNode(NodeInfo(NodeType::HIDDEN, 2));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 3));
    genotype.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype.addEdge(EdgeInfo(2, 3, 1.0, true, 2));

    Phenotype phenotype(genotype);
    EXPECT_EQ(phenotype.getNodes().size(), 4);
    EXPECT_EQ(phenotype.getEdges().size(), 3);

    EXPECT_EQ(1, 1);
}