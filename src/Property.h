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

    int calculateRentPrice() const;
    Color getColor() const;
    bool getIsMortgaged() const;
    int getMortgagePrice() const;
    int getNumberOfHouses() const;
    bool getHasHotel() const;

    void setHasHotel(bool hasHotel);
    void setMortgaged(bool isMortgaged);
    std::vector<PlayerDecisionOutputs> onPlayerEnter(Player* player) override;
    void addHouse();

private:
    void handleOwnedProperty(Player* player, std::vector<PlayerDecisionOutputs> &decisions);
    void handleUpgradableProperty(Player* owner, std::vector<PlayerDecisionOutputs> &decisions);

    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    int numberOfHouses = 0;
    bool hasHotel = false;
    Color color;
};
#endif //PROPERTY_H
