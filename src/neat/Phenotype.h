//
// Created by Maksymilian Baj on 30.12.2024.
//

#ifndef MONOPOLYAI_PHENOTYPE_H
#define MONOPOLYAI_PHENOTYPE_H

#include "Genotype.h"
#include "BaseEdge.h"

namespace NEAT {
    enum class EdgeType {
        FORWARD, RECURRENT
    };

    struct Edge : public BaseEdge {
        EdgeType type = EdgeType::FORWARD;

        Edge(int sourceIdx, int destIdx, double weight, bool isEnabled) :
            BaseEdge(sourceIdx, destIdx, weight, isEnabled) {}

        Edge(BaseEdge edgeInfo, EdgeType type) : BaseEdge(edgeInfo), type(type) {}
    };

    struct Node : public NodeInfo {
        double value;
        std::vector<Edge> incomingEdges;

        Node(NodeType type, int index, double value) : NodeInfo(type, index), value(value) {}
        Node(NodeInfo nodeInfo, double value) : NodeInfo(nodeInfo), value(value) {}
    };

    class Phenotype {
    public:
        explicit Phenotype(const Genotype& genotype);

        std::vector<Node> getNodes() const;
        std::vector<Edge> getEdges() const;

    private:
        std::vector<Node> nodes;
        std::vector<Edge> edges;

        std::vector<Node> inputNodes;
        std::vector<Node> outputNodes;
    };
}

#endif//MONOPOLYAI_PHENOTYPE_H
