//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_SPECIES_H
#define MONOPOLYAI_SPECIES_H

#include <vector>
#include "Genotype.h"
#include "HistoricalMarkings.h"

namespace NEAT {
    class Species {
    public:
        Species() = default;
        Genotype breed(HistoricalMarkings& markings);
        void addMember(const Genotype& member);
        void calcAndSetAdjustedFitness();
        void sortByAdjustedFitness();
        void calculateAdjustedFitnessSum();

        std::vector<Genotype>& getMembers();
        double getFitnessSum() const;

    private:
        std::vector<Genotype> members;
        double topFitness = 0;
        double fitnessSum = 0;
    };
}



#endif//MONOPOLYAI_SPECIES_H
