//
// Created by Maksymilian Baj on 30.12.2024.
//

#ifndef MONOPOLYAI_GENOTYPE_H
#define MONOPOLYAI_GENOTYPE_H
#include <vector>

#include "BaseEdge.h"

namespace NEAT {
    enum class NodeType {
        INPUT,
        HIDDEN,
        OUTPUT
    };
    struct NodeInfo {
        NodeType type;
        int index;

        NodeInfo(NodeType type, int index) : type(type), index(index) {}
    };

    struct EdgeInfo : public BaseEdge {
        int innovation = 0;

        EdgeInfo(int sourceIdx, int destIdx, double weight, bool isEnabled, int innovation) : BaseEdge(sourceIdx, destIdx, weight, isEnabled), innovation(innovation) {}
    };

    class Genotype {
    public:
        Genotype() = default;
        Genotype(const Genotype& other)
            : nodes(other.nodes), edges(other.edges), fitness(other.fitness), adjustedFitness(other.adjustedFitness) {}

        void initialize(int inputsCount, int outputsCount);
        void addNode(NodeInfo node);
        void addEdge(EdgeInfo edge);

        std::vector<NodeInfo> getNodes() const;
        std::vector<EdgeInfo> getEdges() const;
        size_t getNodesCount() const;
        size_t getEdgesCount() const;
        double getAdjustedFitness() const;
        double getFitness() const;

        void setAdjustedFitness(double newFitness);
        void setFitness(double newFitness);
        void sortEdges();
        void sortNodes();

        EdgeInfo& getEdge(int idx);
        std::vector<EdgeInfo>& getEdges();
        void setEdges(const std::vector<EdgeInfo>& newEdges);
        void addEdges(const std::vector<EdgeInfo>& newEdges);

        void getInputAndOutputNodesFromParent(const Genotype& parent);
        void updateHiddenNodes();

    private:
        std::vector<NodeInfo> nodes;
        std::vector<EdgeInfo> edges;

        double fitness = 0;
        double adjustedFitness = 0;
    };

}// namespace NEAT
#endif// MONOPOLYAI_GENOTYPE_H
