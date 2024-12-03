//
// Created by adrwal on 11/6/24.
// class representing a field where player pays tax
//

#ifndef TAXFIELD_H
#define TAXFIELD_H
#include "Field.h"


class TaxField final : public Field {
public:
    TaxField(const std::string& name, Board& board)
        : Field(name, board)
    {
    }

    void onPlayerEnter(Player* player) override ;
};



#endif //TAXFIELD_H
