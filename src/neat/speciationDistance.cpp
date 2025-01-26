//
// Created by Maksymilian Baj on 18.01.2025.
//

#include "speciationDistance.h"
#include "config.h"
#include <valarray>

namespace NEAT {
    double calculateSpeciationDistance(const Genotype& genotype1, const Genotype& genotype2) {
        const double c1 = C1;
        const double c2 = C2;
        const double c3 = C3;
        auto [matchingFirst, matchingSecond, disjoint, excess] = classifyEdges(
                genotype1.getEdges(), genotype2.getEdges());

        size_t N = std::max(genotype1.getEdgesCount(), genotype2.getEdgesCount());
        N = N < 20 ? 1 : N;
        size_t D = disjoint.size();
        size_t E = excess.size();
        double W = getAverageWeightDifference(matchingFirst, matchingSecond);
        return c1 * E / N + c2 * D / N + c3 * W;
    }

    double getAverageWeightDifference(const Edges& edges1, const Edges& edges2) {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < edges1.size(); ++i) {
            sum += std::abs(edges1[i].weight - edges2[i].weight);
            ++count;
        }
        return sum / count;
    }


}// namespace NEAT