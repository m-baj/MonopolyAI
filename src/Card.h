//
// Created by Maksymilian Baj on 25.01.2025.
//

#ifndef MONOPOLYAI_CARD_H
#define MONOPOLYAI_CARD_H

#include <functional>
#include <string>

#include "Player.h"


class Card {
public:
    Card(std::string description, std::function<void(Player*)> action)
        : description(description), action(action) {};

private:
    std::string description;
    std::function<void(Player*)> action;
};


#endif//MONOPOLYAI_CARD_H
