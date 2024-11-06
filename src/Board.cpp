//
// Created by adrwal on 11/3/24.
//

#include "Board.h"

#include "CardField.h"

Board::Board()
{
}

void Board::push_field(std::shared_ptr<Field> field)
{
    this->fields.push_back(field);
}
