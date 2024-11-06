#include <iostream>

#include "src/CardField.h"
#include "src/Game.h"


int main()
{
    Board board;
    Game game = Game(board);
    board.push_field(std::make_shared<Field>("START", board));
    board.push_field(std::make_shared<Property>("MEDITERRANEAN AVENUE", board, 60, 10, 30, Color::BROWN));
    board.push_field(std::make_shared<CardField>("COMMUNITY CHEST", board));

    std::cout << "Hello, World!" << std::endl;
    while (!game.isOver())
    {
        game.playTurn();
    }
    return 0;
}

