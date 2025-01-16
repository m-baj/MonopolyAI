//
// Created by Maksymilian baj on 30.12.2024.
//

#include "Genotype.h"

using namespace NEAT;

void Genotype::addNode(NodeInfo node) {
    nodes.push_back(node);
}

void Genotype::addEdge(EdgeInfo edge) {
    edges.push_back(edge);
}

std::vector<NodeInfo> Genotype::getNodes() const {
    return nodes;
}

std::vector<EdgeInfo> Genotype::getEdges() const {
    return edges;
}

size_t Genotype::getNodesCount() const {
    return nodes.size();
}

size_t Genotype::getEdgesCount() const {
    return edges.size();
}

EdgeInfo& Genotype::getEdge(int idx) {
    return edges[idx];
}