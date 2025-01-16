//
// Created by Maksymilian Baj on 16.01.2025.
//

#include "HistoricalMarkings.h"

using namespace NEAT;

void HistoricalMarkings::registerBaseMarkings(int inputCount, int outputCount) {
    for (int i = 0; i < inputCount; ++i) {
        for (int j = 0; j < outputCount; ++j) {
            markings.emplace_back(markings.size(), i, j + inputCount);
        }
    }
}


int HistoricalMarkings::registerMarking(EdgeInfo edge) {
    for (const auto& marking : markings) {
        if (marking.sourceIdx == edge.sourceIdx && marking.destIdx == edge.destIdx) {
            return marking.innovation;
        }
    }

    markings.emplace_back(markings.size(), edge.sourceIdx, edge.destIdx);
    return markings.size() - 1;
}

std::vector<Marking> HistoricalMarkings::getMarkings() const {
    return markings;
}
