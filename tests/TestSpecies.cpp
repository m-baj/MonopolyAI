//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Species.h"

using namespace NEAT;

TEST(TestBreed, TestBreed) {
    Species species;
    Genotype genotype1;
    Genotype genotype2;
    Genotype genotype3;

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    HistoricalMarkings markings;
    std::vector<Genotype> offspring = species.breed(10, markings);
    EXPECT_EQ(offspring.size(), 10);
}


TEST(TestSpecies, TestCalacAndSetAdjustedFitness) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);
}

TEST(TestSpecies, TestCalacAdjustedFitnessSum) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    species.calculateAdjustedFitnessSum();
    EXPECT_EQ(species.getFitnessSum(), 1 / 3 + 2 / 3 + 3 / 3);
}

TEST(TestSpecies, TestRemoveWeakestMembers) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    species.removeWeakestMembers(0.5);
    EXPECT_EQ(species.getMembers().size(), 2);
}

TEST(TestSpecies, TestIsCompatible) {
    Genotype genotype1;
    genotype1.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype1.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype1.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype1.addEdge(EdgeInfo(0, 3, 1.0, true, 3));

    Genotype genotype2;
    genotype2.addEdge(EdgeInfo(0, 2, 2.0, true, 0));
    genotype2.addEdge(EdgeInfo(1, 2, 2.0, true, 1));
    genotype2.addEdge(EdgeInfo(2, 3, 2.0, true, 2));
    genotype2.addEdge(EdgeInfo(0, 3, 2.0, true, 3));

    Species species;
    species.addMember(genotype1);
    EXPECT_TRUE(species.isCompatible(genotype2));
}

TEST(TestSpecies, TestIsCompatibleFalse) {
    Genotype genotype1;
    genotype1.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype1.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype1.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype1.addEdge(EdgeInfo(0, 3, 1.0, true, 3));

    Genotype genotype2;
    genotype2.addEdge(EdgeInfo(0, 2, 2.0, true, 0));
    genotype2.addEdge(EdgeInfo(1, 2, 2.0, true, 1));
    genotype2.addEdge(EdgeInfo(2, 3, 2.0, true, 2));
    genotype2.addEdge(EdgeInfo(0, 3, 2.0, true, 3));
    genotype2.addEdge(EdgeInfo(0, 4, 2.0, true, 4));

    Species species;
    species.addMember(genotype1);
    EXPECT_FALSE(species.isCompatible(genotype2));
}

TEST(TestSpecies, TestCalcNewNumberOfIndividuals) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    EXPECT_EQ(species.calcNewNumberOfIndividuals(10, 6), 3);
}

TEST(TestSpecies, TestCalcNewNumberOfIndividualsDecrease) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    EXPECT_EQ(species.calcNewNumberOfIndividuals(10, 9), 2);
}

TEST(TestSpecies, TestSortByAdjustedFitness) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    species.sortByAdjustedFitness();
    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1.0 / 3);
}

TEST(TestSpecies, TestReduceMembersToOne) {
    Species species;
    Genotype genotype1;
    genotype1.setFitness(1);
    Genotype genotype2;
    genotype2.setFitness(2);
    Genotype genotype3;
    genotype3.setFitness(3);

    species.addMember(genotype1);
    species.addMember(genotype2);
    species.addMember(genotype3);

    species.calcAndSetAdjustedFitness();

    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
    EXPECT_EQ(species.getMembers()[1].getAdjustedFitness(), 2.0 / 3);
    EXPECT_EQ(species.getMembers()[2].getAdjustedFitness(), 1);

    species.reduceMembersToOne();
    EXPECT_EQ(species.getMembers().size(), 1);
    EXPECT_EQ(species.getMembers()[0].getAdjustedFitness(), 1.0 / 3);
}
