//
// Created by Maksymilian Baj on 16.01.2025.
//

#include "Species.h"
#include "Crossover.h"
#include "Mutation.h"
#include "Random.h"
#include "config.h"
#include "speciationDistance.h"
#include <algorithm>

namespace NEAT {

    Genotype Species::breed(HistoricalMarkings& markings) {
        double roll = randomDouble(0, 1);
        if (roll < CROSSOVER_CHANCE && members.size() > 1) {
            int idx1 = randomInt(0, members.size() - 1);
            int idx2 = randomInt(0, members.size() - 1);
            while (idx1 == idx2) {
                idx2 = randomInt(0, members.size() - 1);
            }
            Genotype child =  crossover(members[idx1], members[idx2]);
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

    void Species::calcAndSetAdjustedFitness() {
        for (Genotype& member : members) {
            member.setAdjustedFitness(member.getFitness() / members.size());
        }
    }

    void Species::addMember(const Genotype& member) {
        members.push_back(member);
    }

    const std::vector<Genotype>& Species::getMembers() const {
        return members;
    }

    void Species::calculateAdjustedFitnessSum() {
        fitnessSum = std::accumulate(members.begin(), members.end(), 0, [](double sum, const Genotype& genotype) {
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
}
