//
// Created by Maksymilian Baj on 30.12.2024.
//

#include "Phenotype.h"

using namespace NEAT;

Phenotype::Phenotype(const NEAT::Genotype& genotype) {
    nodes.reserve(genotype.getNodesCount());
    for (const NodeInfo& node: genotype.getNodes()) {
        nodes.emplace_back(node, 0.0);
    }

    edges.reserve(genotype.getEdgesCount());
    for (const EdgeInfo edgeInfo: genotype.getEdges()) {
        Edge newEdge(edgeInfo.sourceIdx, edgeInfo.destIdx, edgeInfo.weight, edgeInfo.isEnabled);
        edges.push_back(newEdge);
        nodes[edgeInfo.destIdx].incomingEdges.push_back(newEdge);
    }
}

std::vector<Node> Phenotype::getNodes() const {
    return nodes;
}

std::vector<Edge> Phenotype::getEdges() const {
    return edges;
}
