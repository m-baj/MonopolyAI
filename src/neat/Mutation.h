//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_MUTATION_H
#define MONOPOLYAI_MUTATION_H

#include <random>
#include <vector>

#include "Genotype.h"
#include "HistoricalMarkings.h"
#include "config.h"

namespace NEAT {

    void mutateAll(Genotype& genotype, HistoricalMarkings& markings);

    void mutateEdge(Genotype& genotype, HistoricalMarkings& markings);
    void mutateNode(Genotype& genotype, HistoricalMarkings& markings);
    void mutateEnable(Genotype& genotype);
    void mutateDisable(Genotype& genotype);
    void mutateWeight(Genotype& genotype);


    void mutateEnableDisable(Genotype& genotype, bool enable);
    void mutateWeightShift(EdgeInfo& edge, double shiftStep);
    void mutateWeightRandom(EdgeInfo& edge);


}// namespace NEAT

#endif//MONOPOLYAI_MUTATION_H
