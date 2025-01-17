//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_MUTATION_H
#define MONOPOLYAI_MUTATION_H

#include <vector>
#include <random>

#include "Genotype.h"
#include "HistoricalMarkings.h"
#include "config.h"

namespace NEAT {

    class Mutation {
    public:
        Mutation() : rng(std::random_device{}()) {}
        void mutateAll(Genotype& genotype, HistoricalMarkings& markings);

        void mutateEdge(Genotype& genotype, HistoricalMarkings& markings);
        void mutateNode(Genotype& genotype, HistoricalMarkings& markings);
        void mutateEnable(Genotype& genotype);
        void mutateDisable(Genotype& genotype);
        void mutateWeight(Genotype& genotype);

    private:
        void mutateEnableDisable(Genotype& genotype, bool enable);
        void mutateWeightShift(EdgeInfo& edge, double shiftStep);
        void mutateWeightRandom(EdgeInfo& edge);

        std::mt19937 rng;
    };
}// namespace NEAT

#endif//MONOPOLYAI_MUTATION_H
