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
        : name(name), money(startMoney)
    {
    }
private:
    std::vector<std::shared_ptr<Property>> properties = {};
    std::vector<std::shared_ptr<Utilities>> utilities = {};
    std::vector<std::shared_ptr<Trains>> trains = {};
    int money;
    std::string name;
};



#endif //PLAYER_H
