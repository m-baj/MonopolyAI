//
// Created by adrwal on 11/3/24.
//

#include "Game.h"
#include "Board.h"
#include "Constants.h"
#include "./Decision/DecisionSelector.h"
#include "Fields/Field.h"
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
    auto diceRoll = getBoard().rollDice();
    getBoard().movePlayer(diceRoll);

    std::vector<PlayerDecisionOutputs> remainingDecisions = {};
    do
    {
        remainingDecisions = getBoard().getSteppedOnField()->getFieldDecisions(player);
        player->createDecisionSelector()->requireSelection("", remainingDecisions);
    } while (!remainingDecisions.empty());
    getBoard().getCurrentPlayer()->resetMadeTurnDecisions();
    getBoard().nextPlayer();
}
