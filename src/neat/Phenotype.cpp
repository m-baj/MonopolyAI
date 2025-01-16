//
// Created by Maksymilian Baj on 30.12.2024.
//

#include "Phenotype.h"
#include "sigmoid.h"

using namespace NEAT;

Phenotype::Phenotype(const Genotype& genotype) {
    nodes.reserve(genotype.getNodesCount());
    for (const NodeInfo& node : genotype.getNodes()) {
        Node newNode(node, 0);
        nodes.push_back(newNode);

        if (node.type == NodeType::INPUT) {
            inputNodes.emplace_back(nodes.back());
        } else if (node.type == NodeType::OUTPUT) {
            outputNodes.emplace_back(nodes.back());
        }
    }

    edges.reserve(genotype.getEdgesCount());
    for (const EdgeInfo& edgeInfo : genotype.getEdges()) {
        if (edgeInfo.isEnabled) {
            Edge newEdge(edgeInfo.sourceIdx, edgeInfo.destIdx, edgeInfo.weight, edgeInfo.isEnabled);
            edges.push_back(newEdge);
            nodes[edgeInfo.destIdx].incomingEdges.push_back(newEdge);
        }
    }
}

std::vector<Node> Phenotype::getNodes() const {
    return nodes;
}

std::vector<Edge> Phenotype::getEdges() const {
    return edges;
}
std::vector<double> Phenotype::propagate() {
    std::vector<double> outputs;
    outputs.reserve(outputNodes.size());
    for (Node& node : outputNodes) {
        outputs.push_back(propagateNode(node));
    }

    return outputs;
}

double Phenotype::propagateNode(NEAT::Node& node) {
    if (node.type == NodeType::INPUT) {
        return node.value;
    }

    double sum = 0;
    for (const Edge& edge : node.incomingEdges) {
        sum += edge.weight * propagateNode(nodes[edge.sourceIdx]);
    }

    node.value = sum;
    return sigmoid(sum);
}
void Phenotype::setInputValues(const std::vector<double>& inputValues) {
    for (size_t i = 0; i < inputNodes.size(); ++i) {
        inputNodes[i].get().value = inputValues[i];
    }
}
