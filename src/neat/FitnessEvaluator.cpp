//
// Created by adrwal on 11/13/24.
//

#include "FitnessEvaluator.h"

#include <stdexcept>
#include <valarray>

FitnessEvaluator::FitnessEvaluator(const std::vector<Specimen *> &population) {
    this->population = population;

    double baseInverse = 1.0 / GROUP_SIZE;
    double root = std::pow(population.size(), baseInverse);
    if (root != std::floor(root)) {
        throw std::invalid_argument("Population size must be a power of 4");
    }
}

std::vector<Group> FitnessEvaluator::createGroups() const {
    std::vector<Group> groups = {};
    for(int i = 0; i < population.size(); i += GROUP_SIZE) {
        groups.emplace_back(population[i], population[i + 1], population[i + 2], population[i + 3]);
    }
    return groups;
}

Specimen* FitnessEvaluator::getBestInGroup(const Group &group) const {

}
