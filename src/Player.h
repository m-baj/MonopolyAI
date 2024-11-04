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
private:
    std::vector<std::shared_ptr<Property>> properties;
    int money;
    std::string name;

    std::vector<std::shared_ptr<Utilities>> utilities;
    std::vector<std::shared_ptr<Trains>> trains;
};



#endif //PLAYER_H
