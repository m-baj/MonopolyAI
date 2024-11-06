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
    Property(std::string name, int baseBuyPrice, int baseRentPrice, int mortgagePrice, Color color);
    ~Property() override = default;
    void onPlayerEnter() override;
    int calculateRentPrice() const;

private:
    int baseBuyPrice;
    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    Color color;
};



#endif //PROPERTY_H
