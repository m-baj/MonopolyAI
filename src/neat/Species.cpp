//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <algorithm>
#include <cmath>

#include "Crossover.h"
#include "Mutation.h"
#include "Random.h"
#include "Species.h"
#include "config.h"
#include "speciationDistance.h"

namespace NEAT {

    std::vector<Genotype> Species::breed(int offspringCount, HistoricalMarkings& markings) {
        std::vector<Genotype> offspring;
        offspring.reserve(offspringCount);
        for (int i = 0; i < offspringCount; ++i) {
            offspring.push_back(breedOne(markings));
        }
        return offspring;
    }

    Genotype Species::breedOne(HistoricalMarkings& markings) {
        double roll = randomDouble(0, 1);
        if (roll < CROSSOVER_CHANCE && members.size() > 1) {
            int idx1 = randomInt(0, members.size() - 1);
            int idx2 = randomInt(0, members.size() - 1);
            while (idx1 == idx2) {
                idx2 = randomInt(0, members.size() - 1);
            }
            Genotype child = crossover(members[idx1], members[idx2]);
            mutateAll(child, markings);
            return child;
        } else {
            int idx = randomInt(0, members.size() - 1);
            Genotype child = members[idx];
            mutateAll(child, markings);
            return child;
        }
    }

    void Species::sortByAdjustedFitness() {
        std::sort(members.begin(), members.end(), [](const Genotype& a, const Genotype& b) {
            return a.getAdjustedFitness() > b.getAdjustedFitness();
        });
    }

    double Species::calcAndSetAdjustedFitness() {
        double sum = 0;
        for (Genotype& member : members) {
            double adjustedFitness = member.getFitness() / members.size();
            member.setAdjustedFitness(adjustedFitness);
            sum += adjustedFitness;
        }
        fitnessSum = sum;
        return sum;
    }

    void Species::addMember(const Genotype& member) {
        members.push_back(member);
    }

    const std::vector<Genotype>& Species::getMembers() const {
        return members;
    }

    void Species::calculateAdjustedFitnessSum() {
        fitnessSum = std::accumulate(
                members.begin(), members.end(), 0, [](double sum, const Genotype& genotype) {
                    return sum + genotype.getAdjustedFitness();
                });
    }

    double Species::getFitnessSum() const {
        return fitnessSum;
    }

    bool Species::isCompatible(const Genotype& genotype) const {
        double distance = calculateSpeciationDistance(members[0], genotype);
        return distance < SPECIATION_THRESHOLD;
    }

    int Species::calcNewNumberOfIndividuals(int populationSize, double populationFitnessSum) const {
        int newIndividuals = static_cast<int>(std::round((fitnessSum / populationFitnessSum) * populationSize));
        return std::max(1, newIndividuals);
    }

    void Species::removeWeakestMembers(double percentage) {
        int toRemove = members.size() * percentage;
        members.erase(members.end() - toRemove, members.end());
    }

    void Species::reduceMembersToOne() {
        members.erase(members.begin() + 1, members.end());
    }
}// namespace NEAT
