#include <iostream>

#include "src/CardField.h"
#include "src/Game.h"
#include "src/GoToJailField.h"
#include "src/TaxField.h"
#include "src/Utilities.h"


int main()
{
    Board board;
    Game game = Game(board);
    board.push_field(std::make_shared<Field>("START", board));
    board.push_field(std::make_shared<Property>("MEDITERRANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
    board.push_field(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.push_field(std::make_shared<Property>("BALTIC AVENUE", board, 60, 10, 30, Color::BROWN));
    board.push_field(std::make_shared<TaxField>("INCOME TAX", board));
    board.push_field(std::make_shared<Trains>("READING RAILROAD", board));
    board.push_field(std::make_shared<Property>("ORIENTAL AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.push_field(std::make_shared<CardField>("CHANCE", board));
    board.push_field(std::make_shared<Property>("VERMONT AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.push_field(std::make_shared<Property>("CONNECTICUT AVENUE", board, 120, 20, 60, Color::LIGHT_BLUE));
    board.push_field(std::make_shared<Field>("JAIL", board));
    board.push_field(std::make_shared<Property>("ST. CHARLES PLACE", board, 140, 30, 90, Color::PINK));
    board.push_field(std::make_shared<Utilities>("ELECTRIC COMPANY", board));
    board.push_field(std::make_shared<Property>("STATES AVENUE", board, 140, 30, 90, Color::PINK));
    board.push_field(std::make_shared<Property>("VIRGINIA AVENUE", board, 160, 30, 90, Color::PINK));
    board.push_field(std::make_shared<Trains>("PENNSYLVANIA RAILROAD", board));
    board.push_field(std::make_shared<Property>("ST. JAMES PLACE", board, 180, 40, 100, Color::ORANGE));
    board.push_field(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.push_field(std::make_shared<Property>("TENNESSEE AVENUE", board, 180, 40, 100, Color::ORANGE));
    board.push_field(std::make_shared<Property>("NEW YORK AVENUE", board, 200, 40, 100, Color::ORANGE));
    board.push_field(std::make_shared<Field>("FREE PARKING", board));
    board.push_field(std::make_shared<Property>("KENTUCKY AVENUE", board, 220, 50, 150, Color::RED));
    board.push_field(std::make_shared<CardField>("CHANCE", board));
    board.push_field(std::make_shared<Property>("INDIANA AVENUE", board, 220, 50, 150, Color::RED));
    board.push_field(std::make_shared<Property>("ILLINOIS AVENUE", board, 240, 50, 150, Color::RED));
    board.push_field(std::make_shared<Trains>("B. & O. RAILROAD", board));
    board.push_field(std::make_shared<Property>("ATLANTIC AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.push_field(std::make_shared<Property>("VENTNOR AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.push_field(std::make_shared<Utilities>("WATER WORKS", board));
    board.push_field(std::make_shared<Property>("MARVIN GARDENS", board, 280, 60, 180, Color::YELLOW));
    board.push_field(std::make_shared<GoToJailField>("GO TO JAIL", board));
    board.push_field(std::make_shared<Property>("PACIFIC AVENUE", board, 300, 70, 200, Color::GREEN));
    board.push_field(std::make_shared<Property>("NORTH CAROLINA AVENUE", board, 300, 70, 200, Color::GREEN));
    board.push_field(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.push_field(std::make_shared<Property>("PENNSYLVANIA AVENUE", board, 320, 70, 200, Color::GREEN));
    board.push_field(std::make_shared<Trains>("SHORT LINE", board));
    board.push_field(std::make_shared<CardField>("CHANCE", board));
    board.push_field(std::make_shared<Property>("PARK PLACE", board, 350, 100, 200, Color::BLUE));
    board.push_field(std::make_shared<TaxField>("LUXURY TAX", board));
    board.push_field(std::make_shared<Property>("BOARDWALK", board, 400, 100, 200, Color::BLUE));

    board.addPlayer(std::make_unique<Player>("P1", 200));
    board.addPlayer(std::make_unique<Player>("P2", 200));
    board.addPlayer(std::make_unique<Player>("P3", 200));
    board.addPlayer(std::make_unique<Player>("P4", 200));

    while (!game.isOver())
    {
        game.playTurn();
    }
    return 0;
}

