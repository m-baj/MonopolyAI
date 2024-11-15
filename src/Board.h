//
// Created by adrwal on 11/3/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>

#include "Field.h"
#include "Player.h"

// TODO: Add more states
enum class RoundState {
    ROLL_DICE,
    HANDLE_FIELD
};

class GameEvent {};
class BuyFieldEvent : public GameEvent {};
class NotEnoughMoneyEvent : public GameEvent {};

/*
 * Board class is responsible for managing actions caused by players choices.
 * It performs logic which does not require any user input.
 * Mapping user input to actions is done in Game class.
 */
class Board {
public:
    Board();

    Player* getCurrentPlayer() const;
    int getNewPosition(Player* player, int steps) const;
    const std::vector<std::shared_ptr<Field>> &getFields() const;
    const std::vector<std::unique_ptr<Player>> &getPlayers() const;
    bool willMoveCrossStart(Player* player, int steps) const;
    int rollDice() const;
    RoundState getRoundState() const;

    void setCurrentPlayerIndex(int index);
    void pushField(std::shared_ptr<Field> field);
    void pushPlayer(std::unique_ptr<Player> player);
    void setRoundState(RoundState state);

    void movePlayer(int steps);
    void notifyPlayer(Player* player, const GameEvent& event);

private:
    std::vector<std::shared_ptr<Field>> fields = {};
    std::vector<std::unique_ptr<Player>> players = {};
    int currentPlayerIndex = 0;
    RoundState roundState = RoundState::ROLL_DICE;
};



#endif //BOARD_H
