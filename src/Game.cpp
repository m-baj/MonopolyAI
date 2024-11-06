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

        char choice;
        std::cin >> choice;

        // TODO: Validate choice with current round state

        switch (choice)
        {
        case 'a':
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
