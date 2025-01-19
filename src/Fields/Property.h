//
// Created by adrwal on 11/3/24.
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
        : OwnableField(name, board, baseBuyPrice), baseRentPrice(baseRentPrice), mortgagePrice(mortgagePrice), isMortgaged(false), color(color) {};
    ~Property() override = default;

    int calculateRentPrice() const;
    Color getColor() const;
    bool getIsMortgaged() const;
    int getMortgagePrice() const;
    int getUnmortgagePrice() const;
    int getNumberOfHouses() const;
    bool getHasHotel() const;
    int calculateNextHousePrice() const;
    bool canBuyHouseHere(Player* player) const;
    void mortgage();
    void unmortgage();

    void accept(FieldVisitor& visitor) override
    {
        visitor.visitProperty(*this);
        OwnableField::accept(visitor);
    };

    void setHasHotel(bool hasHotel);
    void setMortgaged(bool isMortgaged);
    void onPlayerEnter(Player* player) override;
    std::vector<PlayerDecisionOutputs> getFieldDecisions(Player* player) const override;
    void addHouse();

private:
    int baseRentPrice;
    int mortgagePrice;
    bool isMortgaged;
    int numberOfHouses = 0;
    bool hasHotel = false;
    Color color;
};
#endif //PROPERTY_H
