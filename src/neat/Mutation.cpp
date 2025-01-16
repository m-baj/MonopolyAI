//
// Created by Maksymilian Baj on 16.01.2025.
//

#include <random>

#include "Mutation.h"


namespace NEAT {

    int Mutation::registerMarking(NEAT::EdgeInfo edge) {
        for (const auto& marking : historicalMarkings) {
            if (marking.sourceIdx == edge.sourceIdx && marking.destIdx == edge.destIdx) {
                return marking.innovation;
            }
        }

        historicalMarkings.emplace_back(historicalMarkings.size(), edge.sourceIdx, edge.destIdx);
        return historicalMarkings.size() - 1;
    }

    void Mutation::mutateAll(Genotype& genotype) {
        double mutate_node = MUTATE_NODE;
        double mutate_edge = MUTATE_EDGE;
        double mutate_enable = MUTATE_ENABLE;
        double mutate_disable = MUTATE_DISABLE;
        double mutate_weight = MUTATE_WEIGHT;
        std::mt19937 rng(std::random_device{}());
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
                mutateEdge(genotype);
            }
            --p;
        }

        p = mutate_node;
        while (p > 0) {
            double roll = dist(rng);
            if (roll < p) {
                mutateNode(genotype);
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

    void Mutation::mutateEdge(Genotype& genotype) {
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
                    potentialEdges.emplace_back(i, j, 1.0, true, historicalMarkings.size());
                }
            }
        }
        if (!potentialEdges.empty()) {
            std::mt19937 rng(std::random_device{}());
            std::uniform_int_distribution<size_t> dist(0, potentialEdges.size() - 1);
            size_t idx = dist(rng);
            EdgeInfo mutation = potentialEdges[idx];
            mutation.innovation = registerMarking(mutation);
            genotype.addEdge(potentialEdges[idx]);
        }
    }

    void Mutation::mutateNode(NEAT::Genotype& genotype) {

    }

}// namespace NEAT