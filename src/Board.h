//
// Created by adrwal on 11/3/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>
#include <map>
#include <set>

#include "Field.h"
#include "Player.h"

class Game;
const std::map<Color, int> COLOR_TO_FIELD_COUNT = {
    {Color::BROWN, 2},
    {Color::LIGHT_BLUE, 3},
    {Color::PINK, 3},
    {Color::ORANGE, 3},
    {Color::RED, 3},
    {Color::YELLOW, 3},
    {Color::GREEN, 3},
    {Color::BLUE, 2}
};

// TODO: Add more states
enum class RoundState {
    ROLL_DICE,
    HANDLE_FIELD,
    ACCEPT_PLAYER_DECISIONS,
};

enum class PlayerDecisionOutputs {
    BUY_FIELD, // Buy property, train or utility that player is currently on
    MORTGAGE_FIELD, // Mortgage any owned ownable field
    UNMORTGAGE_FIELD, // Unmortgage any mortgaged field
    BUY_HOUSE, // Buy on property that player is currently on. Buying hotel can be done by buying 5th house.
    SELL_HOUSE, // Sell any house built by player, anywhere. Selling hotel can be done by selling 5th house.
    BAIL_JAIL, // Pay bail to get out of jail
    USE_GET_OUT_OF_JAIL_CARD, // Use get out of jail card to get out of jail
    THROW_DICE, // Throw dice
};

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
    // Game* getPlayedGame() const;

    // static std::unique_ptr<ChoiceSelection> createChoiceSelection(const Decision& decision, const std::string& label);

    void setCurrentPlayerIndex(int index);
    void pushField(std::shared_ptr<Field> field);
    void pushPlayer(std::unique_ptr<Player> player);
    void setRoundState(RoundState state);
    // void setPlayedGame(Game* game);
    void movePlayer(int steps);

    // std::set<PlayerDecisionOutputs> currentPlayerPossibleDecisions = {};

private:
    std::vector<std::shared_ptr<Field>> fields = {};
    std::vector<std::unique_ptr<Player>> players = {};
    int currentPlayerIndex = 0;
    RoundState roundState = RoundState::ROLL_DICE;
    // Game* playedGame;
};



#endif //BOARD_H
