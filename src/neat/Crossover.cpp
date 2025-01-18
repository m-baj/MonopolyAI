//
// Created by Maksymilian Baj on 17.01.2025.
//

#include <unordered_map>

#include "Random.h"
#include "Crossover.h"

namespace NEAT {

    const EdgeInfo& chooseOneMatchingEdge(const EdgeInfo& first, const EdgeInfo& second) {
        if (!first.isEnabled) return second;
        if (!second.isEnabled) return first;
        return randomDouble(0, 1) < 0.5 ? first : second;
    }

    std::tuple<Edges, Edges, Edges> classifyEdges(const Edges& firstEdges, const Edges& secondEdges) {
        std::unordered_map<int, EdgeInfo> secondParentEdges;
        for (const EdgeInfo& edge : secondEdges) {
            secondParentEdges.emplace(edge.innovation, edge);
        }

        Edges matchingEdges;
        Edges disjointEdges;
        Edges excessEdges;

        int invmin = std::min(
                firstEdges.empty() ? 0 : firstEdges.back().innovation,
                secondEdges.empty() ? 0 : secondEdges.back().innovation);

        for (const EdgeInfo& edge : firstEdges) {
            auto it = secondParentEdges.find(edge.innovation);
            if (it != secondParentEdges.end()) {
                matchingEdges.push_back(chooseOneMatchingEdge(edge, it->second));
                secondParentEdges.erase(it);
            } else {
                (edge.innovation < invmin ? disjointEdges : excessEdges).push_back(edge);
            }
        }
        for (const auto& [_, edge] : secondParentEdges) {
            (edge.innovation < invmin ? disjointEdges : excessEdges).push_back(edge);
        }

        return {matchingEdges, disjointEdges, excessEdges};
    }

    Genotype crossover(const Genotype& parent1, const Genotype& parent2) {

        auto [matchingEdges, disjointEdges, excessEdges] = classifyEdges(parent1.getEdges(), parent2.getEdges());

        Genotype child;
        child.setEdges(matchingEdges);
        disjointEdges.insert(disjointEdges.end(), excessEdges.begin(), excessEdges.end());
        child.addEdges(disjointEdges);

        child.sortEdges();
        child.getInputAndOutputNodesFromParent(parent1);
        child.updateHiddenNodes();
        child.sortNodes();

        return child;
    }
}// namespace NEAT