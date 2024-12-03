//
// Created by adrwal on 11/17/24.
// File containing all constants used in the game.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <map>

enum class PlayerDecisionOutputs {
    BUY_FIELD, // Buy property, train or utility that player is currently on
    MORTGAGE_FIELD, // Mortgage any owned ownable field
    UNMORTGAGE_FIELD, // Unmortgage any mortgaged field
    BUY_HOUSE, // Buy on property that player is currently on. Buying hotel can be done by buying 5th house.
    SELL_HOUSE, // Sell any house built by player, anywhere. Selling hotel can be done by selling 5th house.
    BAIL_JAIL, // Pay bail to get out of jail
    JAIL_DICE_ROLL, // Roll dice to get out of jail
    USE_GET_OUT_OF_JAIL_CARD, // Use get out of jail card to get out of jail
    NO_DECISION, // No decision to be made, next player
    THROW_DICE, // Throw dice to move, automatically done by AI.
};

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

const std::map<Color, int> COLOR_TO_FIELD_COUNT = {
    {Color::BROWN, 2},
    {Color::LIGHT_BLUE, 3},
    {Color::PINK, 3},
    {Color::ORANGE, 3},
    {Color::RED, 3},
    {Color::YELLOW, 3},
    {Color::GREEN, 3},
    {Color::BLUE, 2}
};

const int BASE_RENT_FOR_TRAIN = 25;
const int CROSSING_START_BONUS = 200;
const double UNMORTGAGE_INTEREST_MULTIPLIER = 1.1;
const int HOUSE_PRICE = 50;
const int MAX_NUMBER_OF_HOUSES = 5;
// TODO: Remove hotel, replace it with 5th house
const int HOTEL_PRICE = 250;
const int TAX_AMOUNT = 200;

#endif //CONSTANTS_H
