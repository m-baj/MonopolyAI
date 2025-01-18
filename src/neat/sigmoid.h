//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <cmath>

inline double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}