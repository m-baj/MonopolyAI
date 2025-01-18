//
// Created by Maksymilian Baj on 18.01.2025.
//

#include <gtest/gtest.h>

#include "../src/neat/speciationDistance.h"

using namespace NEAT;

TEST(TestSpeciationDistance, TestGetAverageWeightDifference) {
    Genotype genotype1;
    genotype1.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype1.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype1.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype1.addEdge(EdgeInfo(0, 3, 1.0, true, 3));

    Genotype genotype2;
    genotype2.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype2.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype2.addEdge(EdgeInfo(2, 3, 1.0, true, 2));
    genotype2.addEdge(EdgeInfo(0, 3, 1.0, true, 3));

    double averageWeightDifference = getAverageWeightDifference(genotype1.getEdges(), genotype2.getEdges());
    EXPECT_EQ(averageWeightDifference, 0);
}

TEST(TestSpeciationDistance, TestGetAverageWeigthDifferenceDifferentWeights) {
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

    double averageWeightDifference = getAverageWeightDifference(genotype1.getEdges(), genotype2.getEdges());
    EXPECT_EQ(averageWeightDifference, 1);
}

TEST(TestSpeciationDistance, TestCalculateSpeciationDistanceAllMatching) {
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

    double speciationDistance = calculateSpeciationDistance(genotype1, genotype2);
    EXPECT_EQ(speciationDistance, 0.4);
}

TEST(TestSpeciationDistance, TestCalculateSpeciationDistanceOneExcess) {
    Genotype genotype1;
    genotype1.addEdge(EdgeInfo(0, 2, 1.0, true, 0));
    genotype1.addEdge(EdgeInfo(1, 2, 1.0, true, 1));
    genotype1.addEdge(EdgeInfo(2, 3, 1.0, true, 2));

    Genotype genotype2;
    genotype2.addEdge(EdgeInfo(0, 2, 2.0, true, 0));
    genotype2.addEdge(EdgeInfo(1, 2, 2.0, true, 1));
    genotype2.addEdge(EdgeInfo(2, 3, 2.0, true, 2));
    genotype2.addEdge(EdgeInfo(0, 3, 2.0, true, 3));

    double speciationDistance = calculateSpeciationDistance(genotype1, genotype2);
    EXPECT_EQ(speciationDistance, 0.65);
}