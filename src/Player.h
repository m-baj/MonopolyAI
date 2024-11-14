//
// Created by adrwal on 11/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <vector>
#include "OwnableField.h"
#include "Property.h"
#include "Utilities.h"
#include "Trains.h"


class Player {
public:
    Player(const std::string& name, int startMoney)
        : name(name), money(startMoney) {};

    std::string getName() const;
    int getMoney() const;
    int getPositionIdx() const;
    const std::vector<std::shared_ptr<Property>>& getProperties() const;
    const std::vector<std::shared_ptr<Utilities>>& getUtilities() const;
    const std::vector<std::shared_ptr<Trains>>& getTrains() const;

    void setPositionIdx(int positionIdx);
    void pushProperty(std::shared_ptr<Property> property);
    void pushTrain(std::shared_ptr<Trains> train);
    void addMoney(int amount);

    std::optional<Decision> payTo(Player* player, int amount);
    std::optional<Decision> payToBank(int amount);
    bool ownsAllPropertiesOf(Color color) const;
    int getNumberOfTrains() const;

private:
    std::optional<Decision> pay(int amount, Player* player = nullptr);

    std::vector<std::shared_ptr<Property>> properties = {};
    std::vector<std::shared_ptr<Utilities>> utilities = {};
    std::vector<std::shared_ptr<Trains>> trains = {};
    int money;
    std::string name;
    int positionIdx = 0;
};


#endif //PLAYER_H
