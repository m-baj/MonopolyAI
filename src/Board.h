//
// Created by adrwal on 11/3/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>

#include "Field.h"
#include "Player.h"

enum class RoundState {
    ROLL_DICE,
    HANDLE_FIELD,
    HANDLE_PLAYER_CHOICES,
    END_TURN
};

class Board {
public:
    Board();

    Player* getCurrentPlayer() const;
    int getNewPosition(Player* player, int steps) const;
    const std::vector<std::shared_ptr<Field>> &getFields() const {return this->fields;};
    const std::vector<std::unique_ptr<Player>> &getPlayers() const {return this->players;};


    void push_field(std::shared_ptr<Field> field);
    void addPlayer(std::unique_ptr<Player> player);
    int rollDice() const;
    RoundState getRoundState() const {return this->roundState;};
    void movePlayer(int steps);
    bool willMoveCrossStart(Player* player, int steps) const;
    void setCurrentPlayerIndex(int index) {this->currentPlayerIndex = index;};

private:
    // TODO: maybe change to other data type
    std::vector<std::shared_ptr<Field>> fields = {};
    std::vector<std::unique_ptr<Player>> players = {};
    int currentPlayerIndex = 0;
    RoundState roundState = RoundState::ROLL_DICE;


friend class Game;
};



#endif //BOARD_H
