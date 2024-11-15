//
// Created by adrwal on 11/13/24.
//

#ifndef FITNESSEVALUATOR_H
#define FITNESSEVALUATOR_H
#include <vector>

#define GROUP_SIZE 4

class Specimen {};

typedef std::tuple<Specimen*, Specimen*, Specimen*, Specimen*> Group;

class FitnessEvaluator {
public:
    explicit FitnessEvaluator(const std::vector<Specimen*> &population);
    ~FitnessEvaluator() = default;

    std::vector<std::pair<int, Specimen*>> evaluate();

private:
    std::vector<Specimen*> population = {};

    std::vector<Group> createGroups() const;
    Specimen* getBestInGroup(const Group &group) const;
};



#endif //FITNESSEVALUATOR_H
