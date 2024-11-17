//
// Created by adrwal on 11/6/24.
//

#ifndef GOTOJAILFIELD_H
#define GOTOJAILFIELD_H
#include "Field.h"


class GoToJailField final : public Field{
public:
    explicit GoToJailField(const std::string& name, Board& board)
        : Field(name, board)
    {
    }

};



#endif //GOTOJAILFIELD_H
