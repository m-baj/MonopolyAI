//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_POPULATION_H
#define MONOPOLYAI_POPULATION_H

#include <vector>
#include "Species.h"
#include "Genotype.h"
#include "Phenotype.h"

namespace NEAT {

    class Population {
    public:
        Population() = default;
        void createInitialPopulation(int size, int inputsCount, int outputsCount);
        void evaluatePopulation();
        void nextGeneration();
        void addToSpecies(const Genotype& genotype);
        void createNewSpecies(const Genotype& genotype);

        const std::vector<Species>& getSpecies() const;
        const std::vector<Genotype>& getGenotypes() const;

    private:
        std::vector<Species> species;
        std::vector<Genotype> genotypes;
        std::vector<Phenotype> population;
    };
}

#endif//MONOPOLYAI_POPULATION_H
