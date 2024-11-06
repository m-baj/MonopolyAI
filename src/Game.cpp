//
// Created by adrwal on 11/3/24.
//

#include "Game.h"

#include <iostream>

#include "CardField.h"
#include "GoToJailField.h"
#include "TaxField.h"

bool Game::isOver() const
{
    return false;
}

void Game::playTurn()
{
    Player* player = board.getCurrentPlayer();
    std::cout << "Player " << player->getName() << " turn" << std::endl;
    bool endTurn = false;

    while (!endTurn)
    {
        this->displayMenu(board.getRoundState());

        char choice;
        std::cin >> choice;

        // TODO: Validate choice with current round state

        switch (choice)
        {
        case '1':
            {
                auto steps = board.rollDice();
                std::cout << "Rolled " << steps << std::endl;
                board.movePlayer(steps);
                break;
            }
        case 'd':
            {
                this->drawBoard();
                break;
            }
        }

    }
}

void Game::displayMenu(RoundState round_state) const
{
    switch (round_state)
    {
    case RoundState::ROLL_DICE:
        std::cout << "Time to roll dice" << std::endl;
        std::cout << "1. Roll dice" << std::endl;
        std::cout << "d. Display board" << std::endl;
        break;

    }
}

void Game::drawBoard() const
{
    for (int i = 0; i < board.fields.size(); i++)
    {
        std::cout << i+1 << ": ";
        auto& field = board.fields[i];

        std::cout << "(" << field->getName() << ") ";
        auto players = field->getPlayersOnField();
        std::cout << "[ ";
        for (auto& player : players)
        {
            if(player.has_value())
            {
                std::cout << player.value()->getName() << " ";
            }
        }
        std::cout << "] " << std::endl;
    }
}

void Game::addClassicMonopolyFields(Board& board)
{
    board.pushField(std::make_shared<Field>("START", board));
    board.pushField(std::make_shared<Property>("MEDITERRANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("BALTIC AVENUE", board, 60, 10, 30, Color::BROWN));
    board.pushField(std::make_shared<TaxField>("INCOME TAX", board));
    board.pushField(std::make_shared<Trains>("READING RAILROAD", board));
    board.pushField(std::make_shared<Property>("ORIENTAL AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("VERMONT AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<Property>("CONNECTICUT AVENUE", board, 120, 20, 60, Color::LIGHT_BLUE));
    board.pushField(std::make_shared<Field>("JAIL", board));
    board.pushField(std::make_shared<Property>("ST. CHARLES PLACE", board, 140, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Utilities>("ELECTRIC COMPANY", board));
    board.pushField(std::make_shared<Property>("STATES AVENUE", board, 140, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Property>("VIRGINIA AVENUE", board, 160, 30, 90, Color::PINK));
    board.pushField(std::make_shared<Trains>("PENNSYLVANIA RAILROAD", board));
    board.pushField(std::make_shared<Property>("ST. JAMES PLACE", board, 180, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("TENNESSEE AVENUE", board, 180, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<Property>("NEW YORK AVENUE", board, 200, 40, 100, Color::ORANGE));
    board.pushField(std::make_shared<Field>("FREE PARKING", board));
    board.pushField(std::make_shared<Property>("KENTUCKY AVENUE", board, 220, 50, 150, Color::RED));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("INDIANA AVENUE", board, 220, 50, 150, Color::RED));
    board.pushField(std::make_shared<Property>("ILLINOIS AVENUE", board, 240, 50, 150, Color::RED));
    board.pushField(std::make_shared<Trains>("B. & O. RAILROAD", board));
    board.pushField(std::make_shared<Property>("ATLANTIC AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<Property>("VENTNOR AVENUE", board, 260, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<Utilities>("WATER WORKS", board));
    board.pushField(std::make_shared<Property>("MARVIN GARDENS", board, 280, 60, 180, Color::YELLOW));
    board.pushField(std::make_shared<GoToJailField>("GO TO JAIL", board));
    board.pushField(std::make_shared<Property>("PACIFIC AVENUE", board, 300, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<Property>("NORTH CAROLINA AVENUE", board, 300, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
    board.pushField(std::make_shared<Property>("PENNSYLVANIA AVENUE", board, 320, 70, 200, Color::GREEN));
    board.pushField(std::make_shared<Trains>("SHORT LINE", board));
    board.pushField(std::make_shared<CardField>("CHANCE", board));
    board.pushField(std::make_shared<Property>("PARK PLACE", board, 350, 100, 200, Color::BLUE));
    board.pushField(std::make_shared<TaxField>("LUXURY TAX", board));
    board.pushField(std::make_shared<Property>("BOARDWALK", board, 400, 100, 200, Color::BLUE));
}