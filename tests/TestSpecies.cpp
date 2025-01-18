//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/Species.h"

using namespace NEAT;

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
    EXPECT_EQ(species.getFitnessSum(), 1/3 + 2/3 + 3/3);
}
