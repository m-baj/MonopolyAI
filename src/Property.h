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
    void onPlayerEnter(Player* player) override;
    int calculateRentPrice() const;
    std::optional<Player*> getOwner() const;

private:
    void handleOwnedProperty(Player* player, Player* owner);
    void handleUnownedProperty(Player* player);


    int baseBuyPrice;
    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    Color color;
};



#endif //PROPERTY_H
