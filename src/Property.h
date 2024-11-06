//
// Created by adrwal on 11/3/24.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Field.h"

enum class Color {
    BROWN,
    LIGHT_BLUE,
    PINK,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    BLUE
};

class Property final : public Field {
public:
    Property(const std::string& name, Board& board, int baseBuyPrice, int baseRentPrice, int mortgagePrice, Color color)
        : Field(name, board), baseBuyPrice(baseBuyPrice), baseRentPrice(baseRentPrice), mortgagePrice(mortgagePrice), isMortgaged(false), color(color) {};
    ~Property() override = default;
    void onPlayerEnter() override {};
    int calculateRentPrice() const {return 2;};

private:
    int baseBuyPrice;
    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    Color color;
};



#endif //PROPERTY_H
