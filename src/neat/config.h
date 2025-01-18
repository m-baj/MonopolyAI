//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_CONFIG_H
#define MONOPOLYAI_CONFIG_H


const int POPULATION_SIZE = 256;
const int INPUTS_COUNT = 126;
const int OUTPUTS_COUNT = 7;

const double MUTATE_EDGE = 0.2;
const double MUTATE_ENABLE = 0.6;
const double MUTATE_DISABLE = 0.4;
const double MUTATE_WEIGHT = 0.8;
const double MUTATE_NODE = 0.1;

const double PERTURBATION_CHANCE = 0.9;
const double SHIFT_STEP = 0.1;

const double CROSSOVER_CHANCE = 0.75;

const double C1 = 1.0;
const double C2 = 1.0;
const double C3 = 0.4;

const double SPECIATION_THRESHOLD = 1.0;

#endif//MONOPOLYAI_CONFIG_H
