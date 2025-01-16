//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_MUTATION_H
#define MONOPOLYAI_MUTATION_H

#include <vector>

#include "Genotype.h"
#include "config.h"

namespace NEAT {

    struct Marking {
        int innovation;
        int sourceIdx;
        int destIdx;
    };

    class Mutation {
    public:
        Mutation() = default;
        void mutateAll(Genotype& genotype);

        void mutateEdge(Genotype& genotype);
        void mutateNode(Genotype& genotype);
        void mutateEnable(Genotype& genotype) {};
        void mutateDisable(Genotype& genotype) {};
        void mutateWeight(Genotype& genotype) {};

    private:
        int registerMarking(EdgeInfo edge);

        std::vector<Marking> historicalMarkings;
    };
}// namespace NEAT

#endif//MONOPOLYAI_MUTATION_H
