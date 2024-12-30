//
// Created by Maksymilian Baj on 30.12.2024.
//

#ifndef MONOPOLYAI_BASEEDGE_H
#define MONOPOLYAI_BASEEDGE_H

struct BaseEdge {
    int sourceIdx;
    int destIdx;
    double weight;
    bool isEnabled;

    BaseEdge(int sourceIdx, int destIdx, double weight, bool isEnabled) :
        sourceIdx(sourceIdx), destIdx(destIdx), weight(weight), isEnabled(isEnabled) {}
};

#endif//MONOPOLYAI_BASEEDGE_H
