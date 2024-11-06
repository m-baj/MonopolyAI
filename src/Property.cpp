//
// Created by adrwal on 11/3/24.
//

#include "Property.h"

Property::Property(std::string name, const int baseBuyPrice, const int baseRentPrice, const int mortgagePrice, const Color color): Field(name)
{
    this->name = std::move(name);
    this->baseBuyPrice = baseBuyPrice;
    this->baseRentPrice = baseRentPrice;
    this->mortgagePrice = mortgagePrice;
    this->color = color;
    this->isMortgaged = false;
}

void Property::onPlayerEnter()
{
}

int Property::calculateRentPrice() const
{
    if(this->color == Color::RED)
    {
        return 10;
    }
    return 20;
}

 // Field(name), baseBuyPrice(baseBuyPrice), baseRentPrice(baseRentPrice), mortgagePrice(mortgagePrice), isMortgaged(false), color(color) {};