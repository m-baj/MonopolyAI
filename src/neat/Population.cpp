//
// Created by Maksymilian Baj on 16.01.2025.
//

#include "Population.h"
#include "config.h"

namespace NEAT {

    void Population::createInitialPopulation(int size, int inputsCount, int outputsCount) {
        for (int i = 0; i < size; ++i) {
            Genotype genotype;
            genotype.initialize(inputsCount, outputsCount);
            genotypes.push_back(genotype);
        }
        markings.registerBaseMarkings(inputsCount, outputsCount);
    }

    void Population::nextGeneration() {
        double populationFitnessSum = calculateAdjustedFitnessSum();
        breedSpecies(populationFitnessSum);
        for (Genotype& genotype : genotypes) {
            addToSpecies(genotype);
        }
        inscribePhenotypes();
    }

    void Population::breedSpecies(double populationFitnessSum) {
        std::vector<Genotype> newPopulation;
        int populationSize = genotypes.size();
        for (Species& specie : species) {
            specie.sortByAdjustedFitness();
            specie.removeWeakestMembers(PERCENTAGE_OF_WEAKEST_TO_REMOVE);
            int newIndividualsNumber = specie.calcNewNumberOfIndividuals(populationSize, populationFitnessSum);
            std::vector<Genotype> offspring = specie.breed(newIndividualsNumber, markings);
            specie.reduceMembersToOne();
            newPopulation.insert(newPopulation.end(), offspring.begin(), offspring.end());
        }
        genotypes = newPopulation;
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

    double Population::calculateAdjustedFitnessSum() {
        double sum = 0;
        for (Species& specie : species) {
            sum += specie.calcAndSetAdjustedFitness();
        }
        return sum;
    }

    void Population::inscribePhenotypes() {
        for (Genotype& genotype : genotypes) {
            Phenotype phenotype(genotype);
            population.push_back(phenotype);
        }
    }

    const std::vector<Species>& Population::getSpecies() const {
        return species;
    }

    const std::vector<Genotype>& Population::getGenotypes() const {
        return genotypes;
    }


}// namespace NEAT