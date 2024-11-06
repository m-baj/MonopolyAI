//
// Created by adrwal on 11/6/24.
//

#ifndef CARDFIELD_H
#define CARDFIELD_H
#include "Field.h"


class CardField final : public Field {
public:
    explicit CardField(const std::string& name)
        : Field(name)
    {
    }
    void onPlayerEnter() override {};
};



#endif //CARDFIELD_H
