//
// Created by Maksymilian baj on 30.12.2024.
//

#include "Genotype.h"

void NEAT::Genotype::addNode(NEAT::NodeInfo node) {
    nodes.push_back(node);
}

void NEAT::Genotype::addEdge(NEAT::EdgeInfo edge) {
    edges.push_back(edge);
}

std::vector<NEAT::NodeInfo> NEAT::Genotype::getNodes() const {
    return nodes;
}

std::vector<NEAT::EdgeInfo> NEAT::Genotype::getEdges() const {
    return edges;
}