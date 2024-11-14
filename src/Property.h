//
// Created by adrwal on 11/3/24.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "OwnableField.h"

const int HOUSE_PRICE = 50;
const int MAX_NUMBER_OF_HOUSES = 4;
const int HOTEL_PRICE = 250;

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

class Property final : public OwnableField {
public:
    Property(const std::string& name, Board& board, int baseBuyPrice, int baseRentPrice, int mortgagePrice, Color color)
        : OwnableField(name, board, baseBuyPrice), baseRentPrice(baseRentPrice), mortgagePrice(mortgagePrice), isMortgaged(false), color(color) {};
    ~Property() override = default;
    std::optional<Decision> onPlayerEnter(Player* player) override;
    int calculateRentPrice() const;
    Color getColor() const;
    void setMortgaged(bool isMortgaged);
    bool getIsMortgaged() const;
    int getMortgagePrice() const;
    int getNumberOfHouses() const;
    void addHouse();
    bool getHasHotel() const;
    void setHasHotel(bool hasHotel);

private:
    std::optional<Decision> handleOwnedProperty(Player* player);
    std::optional<Decision> handleUnownedProperty(Player* player);
    std::optional<Decision> handleUpgradableProperty(Player* owner);

    Decision unmortgageDecision(Player* player);
    void addBuyHouseDecision(Player* player, Decision& decision);
    void addBuyHotelDecision(Player* player, Decision& decision);
    void addSellHouseDecision(Player* player, Decision& decision);
    Decision sellHotelDecision(Player* player);

    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    int numberOfHouses = 0;
    bool hasHotel = false;
    Color color;
};



#endif //PROPERTY_H
