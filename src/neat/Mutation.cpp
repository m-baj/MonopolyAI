//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <iostream>

#include "Mutation.h"
#include "Random.h"


namespace NEAT {

    void mutateAll(Genotype& genotype, HistoricalMarkings& markings) {
        double mutate_node = MUTATE_NODE;
        double mutate_edge = MUTATE_EDGE;
        double mutate_enable = MUTATE_ENABLE;
        double mutate_disable = MUTATE_DISABLE;
        double mutate_weight = MUTATE_WEIGHT;

        double p = mutate_weight;

        while (p > 0) {
            double roll = randomDouble(0, 1);
            if (roll < p) {
                mutateWeight(genotype);
            }
            --p;
        }

        p = mutate_edge;
        while (p > 0) {
            double roll = randomDouble(0, 1);
            if (roll < p) {
                mutateEdge(genotype, markings);
            }
            --p;
        }

        p = mutate_node;
        while (p > 0) {
            double roll = randomDouble(0, 1);
            if (roll < p) {
                mutateNode(genotype, markings);
            }
            --p;
        }

        p = mutate_enable;
        while (p > 0) {
            double roll = randomDouble(0, 1);
            if (roll < p) {
                mutateEnable(genotype);
            }
            --p;
        }

        p = mutate_disable;
        while (p > 0) {
            double roll = randomDouble(0, 1);
            if (roll < p) {
                mutateDisable(genotype);
            }
            --p;
        }
    }

    void mutateEdge(Genotype& genotype, HistoricalMarkings& markings) {
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
                    double newWeight = randomDouble(-2.0, 2.0);
                    potentialEdges.emplace_back(i, j, newWeight, true, 0);
                }
            }
        }
        if (!potentialEdges.empty()) {
            size_t idx = randomDouble(0, potentialEdges.size() - 1);
            EdgeInfo mutation = potentialEdges[idx];
            mutation.innovation = markings.registerMarking(mutation);
            genotype.addEdge(potentialEdges[idx]);
        }
    }

    void mutateNode(NEAT::Genotype& genotype, HistoricalMarkings& markings) {
        if (genotype.getEdgesCount() == 0) {
            return;
        }

        size_t idx = randomDouble(0, genotype.getEdgesCount() - 1);
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

    void mutateEnableDisable(NEAT::Genotype& genotype, bool enable) {
        std::vector<EdgeInfo*> potentialEdges;
        for (EdgeInfo& edge : genotype.getEdges()) {
            if (edge.isEnabled != enable) {
                potentialEdges.push_back(&edge);
                std::cout << &edge << std::endl;
            }
        }

        if (!potentialEdges.empty()) {
            size_t idx = randomDouble(0, potentialEdges.size() - 1);
            potentialEdges[idx]->isEnabled = enable;
        }
    }

    void mutateEnable(Genotype& genotype) {
        mutateEnableDisable(genotype, true);
    }

    void mutateDisable(NEAT::Genotype& genotype) {
        mutateEnableDisable(genotype, false);
    }

    void mutateWeight(NEAT::Genotype& genotype) {
        if (genotype.getEdgesCount() == 0) {
            return;
        }
        int edgesCount = genotype.getEdgesCount();
        int selection = randomInt(0, edgesCount - 1);
        EdgeInfo& edge = genotype.getEdge(selection);

        double roll = randomDouble(0, 1);
        if (roll < PERTURBATION_CHANCE) {
            mutateWeightShift(edge, SHIFT_STEP);
        } else {
            mutateWeightRandom(edge);
        }
    }

    void mutateWeightShift(EdgeInfo& edge, double shiftStep) {
        edge.weight += randomDouble(-shiftStep / 2, shiftStep / 2);
    }

    void mutateWeightRandom(EdgeInfo& edge) {
        edge.weight = randomDouble(-2.0, 2.0);
    }


}// namespace NEAT