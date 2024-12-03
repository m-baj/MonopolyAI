//
// Created by adrwal on 11/17/24.
//

#include "BoardSetupper.h"

#include "Board.h"
#include "Fields/CardField.h"
#include "Fields/GoToJailField.h"
#include "Fields/Property.h"
#include "Fields/TaxField.h"
#include "Fields/Trains.h"
#include "Fields/Utilities.h"

void BoardSetupCreator::createClassicBoard(Board& board)
{
    board.pushField(std::make_shared<Field>("START", board));
    board.pushField(std::make_shared<Property>("MEDITERRANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("BALTIC AVENUE", board, 60, 10, 30, Color::BROWN));
    board.pushField(std::make_shared<TaxField>("INCOME TAX", board));
    board.pushField(std::make_shared<Trains>("READING RAILROAD", board, BASE_RENT_FOR_TRAIN));
    board.pushField(std::make_shared<Property>("ORIENTAL AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("VERMONT AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<Property>("CONNECTICUT AVENUE", board, 120, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<Field>("JAIL", board));
    board.pushField(std::make_shared<Property>("ST. CHARLES PLACE", board, 140, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Utilities>("ELECTRIC COMPANY", board, 150));
    board.pushField(std::make_shared<Property>("STATES AVENUE", board, 140, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Property>("VIRGINIA AVENUE", board, 160, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Trains>("PENNSYLVANIA RAILROAD", board, BASE_RENT_FOR_TRAIN));
    board.pushField(std::make_shared<Property>("ST. JAMES PLACE", board, 180, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("TENNESSEE AVENUE", board, 180, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<Property>("NEW YORK AVENUE", board, 200, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<Field>("FREE PARKING", board));
    board.pushField(std::make_shared<Property>("KENTUCKY AVENUE", board, 220, 50, 150, Color::RED));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("INDIANA AVENUE", board, 220, 50, 150, Color::RED));
    board.pushField(std::make_shared<Property>("ILLINOIS AVENUE", board, 240, 50, 150, Color::RED));
    board.pushField(std::make_shared<Trains>("B. & O. RAILROAD", board, BASE_RENT_FOR_TRAIN));
    board.pushField(std::make_shared<Property>("ATLANTIC AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<Property>("VENTNOR AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<Utilities>("WATER WORKS", board, 150));
    board.pushField(std::make_shared<Property>("MARVIN GARDENS", board, 280, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<GoToJailField>("GO TO JAIL", board));
    board.pushField(std::make_shared<Property>("PACIFIC AVENUE", board, 300, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<Property>("NORTH CAROLINA AVENUE", board, 300, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("PENNSYLVANIA AVENUE", board, 320, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<Trains>("SHORT LINE", board, BASE_RENT_FOR_TRAIN));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("PARK PLACE", board, 350, 100, 200, Color::BLUE));
    board.pushField(std::make_shared<TaxField>("LUXURY TAX", board));
    board.pushField(std::make_shared<Property>("BOARDWALK", board, 400, 100, 200, Color::BLUE));
}
