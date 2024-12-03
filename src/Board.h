//
// Created by adrwal on 11/3/24.
// Class representing a game board_
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>

#include "Fields/Field.h"
#include "Player.h"

/*
 * Board class is responsible for managing actions caused by players_ choices.
 * It performs logic which does not require any user input.
 * Mapping user input to actions is done in Game class.
 */
class Board {
public:
    Board();
    ~Board() = default;

    Player* getCurrentPlayer() const;
    int getNewPosition(Player* player, int steps) const;
    const std::vector<std::shared_ptr<Field>>& getFields() const;
    const std::vector<std::unique_ptr<Player>>& getPlayers() const;
    bool willMoveCrossStart(Player* player, int steps) const;
    int rollDice() const;
    Field* getSteppedOnField() const;

    void setCurrentPlayerIndex(int index);
    void pushField(std::shared_ptr<Field> field);
    void pushPlayer(std::unique_ptr<Player> player);
    void movePlayer(int steps);
    void nextPlayer();

private:
    std::vector<std::shared_ptr<Field>> fields_ = {};
    std::vector<std::unique_ptr<Player>> players_ = {};
    int currentPlayerIndex_ = 0;
};


#endif//BOARD_H
