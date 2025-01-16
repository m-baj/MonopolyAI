//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_MUTATION_H
#define MONOPOLYAI_MUTATION_H

#include <vector>

#include "Genotype.h"
#include "config.h"
#include "HistoricalMarkings.h"

namespace NEAT {

    class Mutation {
    public:
        Mutation() = default;
        void mutateAll(Genotype& genotype, HistoricalMarkings& markings);

        void mutateEdge(Genotype& genotype, HistoricalMarkings& markings);
        void mutateNode(Genotype& genotype, HistoricalMarkings& markings);
        void mutateEnable(Genotype& genotype, HistoricalMarkings& markings);
        void mutateDisable(Genotype& genotype, HistoricalMarkings& markings) {};
        void mutateWeight(Genotype& genotype, HistoricalMarkings& markings) {};
    };
}// namespace NEAT

#endif//MONOPOLYAI_MUTATION_H
