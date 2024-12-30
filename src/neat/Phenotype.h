//
// Created by Maksymilian Baj on 30.12.2024.
//

#ifndef MONOPOLYAI_PHENOTYPE_H
#define MONOPOLYAI_PHENOTYPE_H

#include "Genotype.h"
#include "BaseEdge.h"

namespace NEAT {

    struct Node : public NodeInfo {
        double value;

        Node(NodeType type, int index, double value) : NodeInfo(type, index), value(value) {}
    };

    enum class EdgeType {
        FORWARD, RECURRENT
    };

    struct Edge : public BaseEdge {
        EdgeType type;

        Edge(int sourceIdx, int destIdx, double weight, bool isEnabled, EdgeType type) :
                                                                                         BaseEdge(sourceIdx, destIdx, weight, isEnabled), type(type) {}
    };

    class Phenotype {
    public:
        explicit Phenotype(const Genotype& genotype);


    private:
        std::vector<Node> nodes;
        std::vector<Edge> edges;

        std::vector<Node> inputNodes;
        std::vector<Node> outputNodes;
    };
}

#endif//MONOPOLYAI_PHENOTYPE_H
