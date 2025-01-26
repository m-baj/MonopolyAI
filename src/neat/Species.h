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
        std::vector<Genotype> breed(int offspringCount, HistoricalMarkings& markings);

        bool isCompatible(const Genotype& genotype) const;

        void addMember(const Genotype& member);
        double calcAndSetAdjustedFitness();
        int calcNewNumberOfIndividuals(int populationSize, double populationFitnessSum) const;
        void removeWeakestMembers(double percentage);
        void sortByAdjustedFitness();
        void calculateAdjustedFitnessSum();
        void reduceMembersToOne();

        const std::vector<Genotype>& getMembers() const;
        double getFitnessSum() const;

    private:
        Genotype breedOne(HistoricalMarkings& markings);

        std::vector<Genotype> members;
        double topFitness = 0;
        double fitnessSum = 0;
    };
}



#endif//MONOPOLYAI_SPECIES_H
