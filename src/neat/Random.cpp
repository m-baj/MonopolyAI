//
// Created by Maksymilian Baj on 18.01.2025.
//

#include "Random.h"

namespace NEAT {
    static std::mt19937 rng(std::random_device{}());

    int randomInt(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(rng);
    }

    double randomDouble(double min, double max) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(rng);
    }
}