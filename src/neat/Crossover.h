//
// Created by Maksymilian Baj on 17.01.2025.
//

#ifndef MONOPOLYAI_CROSSOVER_H
#define MONOPOLYAI_CROSSOVER_H

#include "Genotype.h"

namespace NEAT {

    using Edges = std::vector<EdgeInfo>;

    Genotype crossover(const Genotype& parent1, const Genotype& parent2);
    std::tuple<Edges, Edges, Edges, Edges> classifyEdges(const Edges& firstEdges, const Edges& secondEdges);
    const EdgeInfo& chooseOneMatchingEdge(const EdgeInfo& first, const EdgeInfo& second);
}// namespace NEAT

#endif//MONOPOLYAI_CROSSOVER_H
