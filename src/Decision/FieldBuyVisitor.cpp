//
// Created by adrwal on 1/19/25.
//

#include "FieldBuyVisitor.h"

#include "../Board.h"
#include "../Fields/Property.h"

void FieldBuyVisitor::visitProperty(Property& field)
{
    field.setOwner(field.getBoard().getCurrentPlayer());
    field.getBoard().getCurrentPlayer()->pushProperty(std::make_shared<Property>(field));
    field.getBoard().getCurrentPlayer()->payToBank(field.getBaseBuyPrice());
}
