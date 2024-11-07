//
// Created by adrwal on 11/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <vector>

#include "Property.h"
#include "Trains.h"
#include "Utilities.h"


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
    void addMoney(int amount);

private:
    std::vector<std::shared_ptr<Property>> properties = {};
    std::vector<std::shared_ptr<Utilities>> utilities = {};
    std::vector<std::shared_ptr<Trains>> trains = {};
    int money;
    std::string name;
    int positionIdx = 0;
};


#endif //PLAYER_H
