//
// Created by adrwal on 11/3/24.
//

#include "Game.h"
#include "Board.h"
#include "Constants.h"
#include "Decision.h"
#include "Field.h"
#include "Player.h"


Board & Game::getBoard() const {
    return board;
}

bool Game::isOver() const
{
    return false;
}

void Game::play()
{
    while (!this->isOver())
    {
        this->nextTurn();
    }
}

void Game::nextTurn()
{
    Player* player = getBoard().getCurrentPlayer();
    player->createDecisionSelector()->requireSelection("", {PlayerDecisionOutputs::THROW_DICE});
    auto diceRol = getBoard().rollDice();
    getBoard().movePlayer(diceRol);

    std::vector<PlayerDecisionOutputs> remainingDecisions = {};
    do
    {
        remainingDecisions = getBoard().getSteppedOnField()->getFieldDecisions(player);
        player->createDecisionSelector()->requireSelection("", remainingDecisions);
    } while (!remainingDecisions.empty());
    getBoard().nextPlayer();
}

// bool GameCli::isOver() const
// {
//     return false;
// }
//
// void GameCli::play()
// {
//     // getBoard().setPlayedGame(this);
//     Player* player = getBoard().getCurrentPlayer();
//     std::cout << "Player " << player->getName() << " turn" << std::endl;
//     bool endTurn = false;
//
//     while (!endTurn)
//     {
//         this->displayMenu(getBoard().getRoundState());
//
//         char choice;
//         std::cin >> choice;
//
//         // TODO: validate choice with current round state
//
//         switch (choice)
//         {
//         case '1':
//             {
//                 auto steps = getBoard().rollDice();
//                 std::cout << "Rolled " << steps << std::endl;
//                 getBoard().movePlayer(steps);
//                 break;
//             }
//         case 'd':
//             {
//                 this->drawBoard();
//                 break;
//             }
//         }
//
//     }
// }
//
// bool GameNonInteractive::isOver() const
// {
//     return false;
// }
//
// void GameNonInteractive::play()
// {
//     while (!this->isOver())
//     {
//         Player* player = getBoard().getCurrentPlayer();
//         player->createDecisionSelector()->requireSelection("", {PlayerDecisionOutputs::THROW_DICE});
//         auto diceRol = getBoard().rollDice();
//         getBoard().movePlayer(diceRol);
//
//         std::vector<PlayerDecisionOutputs> remainingDecisions = {};
//         do
//         {
//             remainingDecisions = getBoard().getSteppedOnField()->getFieldDecisions();
//             player->createDecisionSelector()->requireSelection("", remainingDecisions);
//         } while (!remainingDecisions.empty());
//     }
// }
//
// void GameCli::displayMenu(RoundState round_state) const
// {
//     switch (round_state)
//     {
//     case RoundState::WAIT_FOR_ROLL_DICE:
//         std::cout << "Time to roll dice" << std::endl;
//         std::cout << "1. Roll dice" << std::endl;
//         std::cout << "d. Display board" << std::endl;
//         break;
//
//     }
// }
//
// void GameCli::drawBoard() const
// {
//     for (int i = 0; i < getBoard().getFields().size(); i++)
//     {
//         std::cout << i+1 << ": ";
//         auto& field = getBoard().getFields()[i];
//
//         std::cout << "(" << field->getName() << ") ";
//         auto players = field->getPlayersOnField();
//         std::cout << "[ ";
//         for (auto& player : players)
//         {
//             if(player.has_value())
//             {
//                 std::cout << player.value()->getName() << " ";
//             }
//         }
//         std::cout << "] " << std::endl;
//     }
// }
//
// void GameCli::addClassicMonopolyFields(Board& board)
// {
//     board.pushField(std::make_shared<Field>("START", board));
//     board.pushField(std::make_shared<Property>("MEDITERRANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
//     board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
//     board.pushField(std::make_shared<Property>("BALTIC AVENUE", board, 60, 10, 30, Color::BROWN));
//     board.pushField(std::make_shared<TaxField>("INCOME TAX", board));
//     board.pushField(std::make_shared<Trains>("READING RAILROAD", board, BASE_RENT_FOR_TRAIN));
//     board.pushField(std::make_shared<Property>("ORIENTAL AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
//     board.pushField(std::make_shared<CardField>("CHANCE", board));
//     board.pushField(std::make_shared<Property>("VERMONT AVENUE", board, 100, 20, 60, Color::LIGHT_BLUE));
//     board.pushField(std::make_shared<Property>("CONNECTICUT AVENUE", board, 120, 20, 60, Color::LIGHT_BLUE));
//     board.pushField(std::make_shared<Field>("JAIL", board));
//     board.pushField(std::make_shared<Property>("ST. CHARLES PLACE", board, 140, 30, 90, Color::PINK));
//     board.pushField(std::make_shared<Utilities>("ELECTRIC COMPANY", board, 150));
//     board.pushField(std::make_shared<Property>("STATES AVENUE", board, 140, 30, 90, Color::PINK));
//     board.pushField(std::make_shared<Property>("VIRGINIA AVENUE", board, 160, 30, 90, Color::PINK));
//     board.pushField(std::make_shared<Trains>("PENNSYLVANIA RAILROAD", board, BASE_RENT_FOR_TRAIN));
//     board.pushField(std::make_shared<Property>("ST. JAMES PLACE", board, 180, 40, 100, Color::ORANGE));
//     board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
//     board.pushField(std::make_shared<Property>("TENNESSEE AVENUE", board, 180, 40, 100, Color::ORANGE));
//     board.pushField(std::make_shared<Property>("NEW YORK AVENUE", board, 200, 40, 100, Color::ORANGE));
//     board.pushField(std::make_shared<Field>("FREE PARKING", board));
//     board.pushField(std::make_shared<Property>("KENTUCKY AVENUE", board, 220, 50, 150, Color::RED));
//     board.pushField(std::make_shared<CardField>("CHANCE", board));
//     board.pushField(std::make_shared<Property>("INDIANA AVENUE", board, 220, 50, 150, Color::RED));
//     board.pushField(std::make_shared<Property>("ILLINOIS AVENUE", board, 240, 50, 150, Color::RED));
//     board.pushField(std::make_shared<Trains>("B. & O. RAILROAD", board, BASE_RENT_FOR_TRAIN));
//     board.pushField(std::make_shared<Property>("ATLANTIC AVENUE", board, 260, 60, 180, Color::YELLOW));
//     board.pushField(std::make_shared<Property>("VENTNOR AVENUE", board, 260, 60, 180, Color::YELLOW));
//     board.pushField(std::make_shared<Utilities>("WATER WORKS", board, 150));
//     board.pushField(std::make_shared<Property>("MARVIN GARDENS", board, 280, 60, 180, Color::YELLOW));
//     board.pushField(std::make_shared<GoToJailField>("GO TO JAIL", board));
//     board.pushField(std::make_shared<Property>("PACIFIC AVENUE", board, 300, 70, 200, Color::GREEN));
//     board.pushField(std::make_shared<Property>("NORTH CAROLINA AVENUE", board, 300, 70, 200, Color::GREEN));
//     board.pushField(std::make_shared<CardField>("COMMUNITY CHEST", board));
//     board.pushField(std::make_shared<Property>("PENNSYLVANIA AVENUE", board, 320, 70, 200, Color::GREEN));
//     board.pushField(std::make_shared<Trains>("SHORT LINE", board, BASE_RENT_FOR_TRAIN));
//     board.pushField(std::make_shared<CardField>("CHANCE", board));
//     board.pushField(std::make_shared<Property>("PARK PLACE", board, 350, 100, 200, Color::BLUE));
//     board.pushField(std::make_shared<TaxField>("LUXURY TAX", board));
//     board.pushField(std::make_shared<Property>("BOARDWALK", board, 400, 100, 200, Color::BLUE));
// }

// std::unique_ptr<ChoiceSelection> GameCli::createChoiceSelection(const Decision& decision, const std::string& label) const {
//     return std::make_unique<ConsoleChoiceSelection>(decision, label);
// }
