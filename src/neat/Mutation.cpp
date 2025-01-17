//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <iostream>
#include <random>

#include "Mutation.h"


namespace NEAT {

    void Mutation::mutateAll(Genotype& genotype, HistoricalMarkings& markings) {
        double mutate_node = MUTATE_NODE;
        double mutate_edge = MUTATE_EDGE;
        double mutate_enable = MUTATE_ENABLE;
        double mutate_disable = MUTATE_DISABLE;
        double mutate_weight = MUTATE_WEIGHT;
        std::uniform_real_distribution<double> dist(0.0, 1.0);

        double p = mutate_weight;

        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateWeight(genotype);
            }
            --p;
        }

        p = mutate_edge;
        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateEdge(genotype, markings);
            }
            --p;
        }

        p = mutate_node;
        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateNode(genotype, markings);
            }
            --p;
        }

        p = mutate_enable;
        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateEnable(genotype);
            }
            --p;
        }

        p = mutate_disable;
        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateDisable(genotype);
            }
            --p;
        }
    }

    void Mutation::mutateEdge(Genotype& genotype, HistoricalMarkings& markings) {
        std::vector<EdgeInfo> potentialEdges;
        for (size_t i = 0; i < genotype.getNodesCount(); ++i) {
            for (size_t j = 0; j < genotype.getNodesCount(); ++j) {
                NodeInfo source = genotype.getNodes()[i];
                NodeInfo dest = genotype.getNodes()[j];

                if (source.index == dest.index) {
                    continue;
                }
                if (source.type == NodeType::OUTPUT || dest.type == NodeType::INPUT) {
                    continue;
                }

                bool edgeExists = false;
                for (const EdgeInfo& edge : genotype.getEdges()) {
                    if (edge.sourceIdx == i && edge.destIdx == j) {
                        edgeExists = true;
                        break;
                    }
                }

                if (!edgeExists) {
                    std::uniform_real_distribution<double> dist(-1.0, 1.0);
                    double newWeight = dist(rng);
                    potentialEdges.emplace_back(i, j, newWeight, true, 0);
                }
            }
        }
        if (!potentialEdges.empty()) {
            std::uniform_int_distribution<size_t> dist(0, potentialEdges.size() - 1);
            size_t idx = dist(rng);
            EdgeInfo mutation = potentialEdges[idx];
            mutation.innovation = markings.registerMarking(mutation);
            genotype.addEdge(potentialEdges[idx]);
        }
    }

    void Mutation::mutateNode(NEAT::Genotype& genotype, HistoricalMarkings& markings) {
        if (genotype.getEdgesCount() == 0) {
            return;
        }

        std::uniform_int_distribution<size_t> dist(0, genotype.getEdgesCount() - 1);
        size_t idx = dist(rng);
        EdgeInfo& edge = genotype.getEdge(idx);
        if (!edge.isEnabled) {
            return;
        }

        edge.isEnabled = false;

        int newNodeIdx = genotype.getNodes()[genotype.getNodesCount() - 1].index + 1;

        NodeInfo newNode(NodeType::HIDDEN, newNodeIdx);

        EdgeInfo edge1(edge.sourceIdx, newNode.index, 1.0, true, 0);
        EdgeInfo edge2(newNode.index, edge.destIdx, edge.weight, true, 0);
        edge1.innovation = markings.registerMarking(edge1);
        edge2.innovation = markings.registerMarking(edge2);

        genotype.addNode(newNode);
        genotype.addEdge(edge1);
        genotype.addEdge(edge2);
    }

    void Mutation::mutateEnableDisable(NEAT::Genotype& genotype, bool enable) {
        std::vector<EdgeInfo*> potentialEdges;
        for (EdgeInfo& edge : genotype.getEdges()) {
            if (edge.isEnabled != enable) {
                potentialEdges.push_back(&edge);
                std::cout << &edge << std::endl;
            }
        }

        if (!potentialEdges.empty()) {
            std::uniform_int_distribution<size_t> dist(0, potentialEdges.size() - 1);
            size_t idx = dist(rng);
            potentialEdges[idx]->isEnabled = enable;
        }
    }

    void Mutation::mutateEnable(Genotype& genotype) {
        mutateEnableDisable(genotype, true);
    }

    void Mutation::mutateDisable(NEAT::Genotype& genotype) {
        mutateEnableDisable(genotype, false);
    }

    void Mutation::mutateWeight(NEAT::Genotype& genotype) {
        if (genotype.getEdgesCount() == 0) {
            return;
        }
        int edgesCount = genotype.getEdgesCount();
        int selection = std::uniform_int_distribution<int>(0, edgesCount - 1)(rng);
        EdgeInfo& edge = genotype.getEdge(selection);

        double roll = std::uniform_real_distribution<double>(0.0, 1.0)(rng);
        if (roll < PERTURBATION_CHANCE) {
            mutateWeightShift(edge, SHIFT_STEP);
        } else {
            mutateWeightRandom(edge);
        }
    }

    void Mutation::mutateWeightShift(EdgeInfo& edge, double shiftStep) {
        std::uniform_real_distribution<double> dist(-shiftStep/2, shiftStep/2);
        edge.weight += dist(rng);
    }

    void Mutation::mutateWeightRandom(EdgeInfo& edge) {
        std::uniform_real_distribution<double> dist(-2.0, 2.0);
        edge.weight = dist(rng);
    }


}// namespace NEAT