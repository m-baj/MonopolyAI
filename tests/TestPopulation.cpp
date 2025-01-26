//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Population.h"

using namespace NEAT;

TEST(TestPopulation, TestCreateInitialPopulation) {
    Population population;
    population.createInitialPopulation(10, 3, 2);
    EXPECT_EQ(population.getGenotypes().size(), 10);
    for (const Genotype& genotype : population.getGenotypes()) {
        EXPECT_EQ(genotype.getNodesCount(), 5);
        EXPECT_EQ(genotype.getEdgesCount(), 1);
    }
}

TEST(TestPopulation, TestAddToSpecies) {
    Population population;
    Genotype genotype;
    genotype.initialize(3, 2);
    population.addToSpecies(genotype);
    EXPECT_EQ(population.getSpecies().size(), 1);
    EXPECT_EQ(population.getSpecies()[0].getMembers().size(), 1);
    EXPECT_EQ(population.getSpecies()[0].getMembers()[0].getNodesCount(), 5);
    EXPECT_EQ(population.getSpecies()[0].getMembers()[0].getEdgesCount(), 1);
}

TEST(TestPopulation, TestAddToSpeciesMultiple) {
    Population population;
    Genotype genotype1;
    genotype1.initialize(3, 2);
    Genotype genotype2;
    genotype2.initialize(3, 2);
    Genotype genotype3;
    genotype3.initialize(3, 2);
    population.addToSpecies(genotype1);
    population.addToSpecies(genotype2);
    population.addToSpecies(genotype3);
    EXPECT_EQ(population.getSpecies().size(), 1);
    EXPECT_EQ(population.getSpecies()[0].getMembers().size(), 3);
}

TEST(TestPopulation, TestAddToSpeciesNewSpecies) {
    Population population;
    Genotype genotype1;
    genotype1.initialize(3, 2);
    Genotype genotype2;
    genotype2.initialize(3, 2);
    population.addToSpecies(genotype1);
    population.addToSpecies(genotype2);
    EXPECT_EQ(population.getSpecies().size(), 1);
    Genotype genotype3;
    genotype3.initialize(3, 2);
    EdgeInfo edge(0, 1, 0.5, true, 1);
    genotype3.addEdge(edge);
    EdgeInfo edge2(1, 2, 0.5, true, 2);
    genotype3.addEdge(edge2);
    NodeInfo node(NodeType::HIDDEN, 5);
    genotype3.addNode(node);
    population.addToSpecies(genotype3);
    EXPECT_EQ(population.getSpecies().size(), 2);
}
