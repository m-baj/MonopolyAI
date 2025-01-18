//
// Created by Maksymilian Baj on 30.12.2024.
//

#include <gtest/gtest.h>
#include "../src/neat/Phenotype.h"
#include "../src/neat/sigmoid.h"

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
}

TEST(TestPhenotype, TestCreatePhenotypeFromGenotypeDisabledEdge)
{
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::INPUT, 1));
    genotype.addNode(NodeInfo(NodeType::HIDDEN, 2));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 3));
    genotype.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype.addEdge(EdgeInfo(1, 2, 1.0, false, 1));
    genotype.addEdge(EdgeInfo(2, 3, 1.0, true, 2));

    Phenotype phenotype(genotype);
    EXPECT_EQ(phenotype.getNodes().size(), 4);
    EXPECT_EQ(phenotype.getEdges().size(), 2);
}

TEST(TestPhenotype, TestCreatePhenotypeFromGenotypeRecurentEdge)
{
    Genotype genotype;
    genotype.addNode(NodeInfo(NodeType::INPUT, 0));
    genotype.addNode(NodeInfo(NodeType::INPUT, 1));
    genotype.addNode(NodeInfo(NodeType::HIDDEN, 2));
    genotype.addNode(NodeInfo(NodeType::OUTPUT, 3));
    genotype.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype.addEdge(EdgeInfo(3, 2, 1.0, true, 3));

    Phenotype phenotype(genotype);
    EXPECT_EQ(phenotype.getNodes().size(), 4);
    EXPECT_EQ(phenotype.getEdges().size(), 4);
}

TEST(TestPhenotype, TestPropagate)
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
    phenotype.setInputValues({1.0, 1.0});
    std::vector<double> outputs = phenotype.propagate();
    EXPECT_EQ(outputs.size(), 1);
    double output = sigmoid(sigmoid(2.0));
    EXPECT_EQ(outputs[0], output);
}
