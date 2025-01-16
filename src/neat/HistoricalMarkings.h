//
// Created by Maksymilian Baj on 16.01.2025.
//

#ifndef MONOPOLYAI_HISTORICALMARKINGS_H
#define MONOPOLYAI_HISTORICALMARKINGS_H

#include <vector>

#include "Genotype.h"

namespace NEAT {
    struct Marking {
        int innovation;
        int sourceIdx;
        int destIdx;
    };
    class HistoricalMarkings {
    public:
        void registerBaseMarkings(int inputCount, int outputCount);
        int registerMarking(EdgeInfo edge);

        std::vector<Marking> getMarkings() const;
    private:
        std::vector<Marking> markings;
    };
}// namespace NEAT


#endif//MONOPOLYAI_HISTORICALMARKINGS_H
