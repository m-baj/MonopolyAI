//
// Created by adrwal on 11/3/24.
// Class representing a property field on the board_.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "../Constants.h"
#include "OwnableField.h"


class Player;

// TODO: Remove hotel, replace it with 5th house
class Property final : public OwnableField {
public:
    Property(const std::string& name, Board& board, int baseBuyPrice, int baseRentPrice, int mortgagePrice, Color color)
        : OwnableField(name, board, baseBuyPrice), baseRentPrice_(baseRentPrice), mortgagePrice_(mortgagePrice), isMortgaged_(false), color_(color) {};
    ~Property() override = default;

    int calculateRentPrice() const;
    Color getColor() const;
    bool getIsMortgaged() const;
    int getMortgagePrice() const;
    int getNumberOfHouses() const;
    bool getHasHotel() const;
    int calculateNextHousePrice() const;
    bool canBuyHouseHere(Player* player) const;

    void setHasHotel(bool hasHotel);
    void setMortgaged(bool isMortgaged);
    void onPlayerEnter(Player* player) override;
    std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const override;
    void addHouse();

private:
    int baseRentPrice_;
    int mortgagePrice_;
    bool isMortgaged_;
    int numberOfHouses_ = 0;
    bool hasHotel_ = false;
    Color color_;
};
#endif//PROPERTY_H
