//
// Created by adrwal on 11/3/24.
//

#include "Field.h"

#include <utility>

Field::Field(std::string name)
{
    this->name = std::move(name);
}
