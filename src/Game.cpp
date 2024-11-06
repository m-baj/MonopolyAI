//
// Created by adrwal on 11/3/24.
//

#include "Game.h"

#include <iostream>

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

        int choice;
        std::cin >> choice;

        // TODO: Validate choice with current round state

        switch (choice)
        {
        case 1:
            break;
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
        break;

    }
}
