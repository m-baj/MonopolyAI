//
// Created by Maksymilian Baj on 18.01.2025.
//

#ifndef MONOPOLYAI_SPECIATIONDISTANCE_H
#define MONOPOLYAI_SPECIATIONDISTANCE_H

#include "Crossover.h"
#include "Genotype.h"

namespace NEAT {
    double calculateSpeciationDistance(const Genotype& genotype1, const Genotype& genotype2);
    double getAverageWeightDifference(const Edges& edges1 , const Edges& edges2);
}

#endif//MONOPOLYAI_SPECIATIONDISTANCE_H