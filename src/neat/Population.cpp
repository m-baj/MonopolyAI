//
// Created by Maksymilian Baj on 16.01.2025.
//

#include "Population.h"

namespace NEAT {

    void Population::createInitialPopulation(int size, int inputsCount, int outputsCount) {
        for (int i = 0; i < size; ++i) {
            Genotype genotype;
            genotype.initialize(inputsCount, outputsCount);
            genotypes.push_back(genotype);
        }
    }

    void Population::addToSpecies(const Genotype& genotype) {
        if (species.empty()) {
            createNewSpecies(genotype);
            return;
        }

        for (Species& specie : species) {
            if (specie.isCompatible(genotype)) {
                specie.addMember(genotype);
                return;
            }
        }
        createNewSpecies(genotype);
    }

    void Population::createNewSpecies(const Genotype& genotype) {
        Species newSpecies;
        newSpecies.addMember(genotype);
        species.push_back(newSpecies);
    }

    const std::vector<Species>& Population::getSpecies() const {
        return species;
    }

    const std::vector<Genotype>& Population::getGenotypes() const {
        return genotypes;
    }

}// namespace NEAT