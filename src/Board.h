//
// Created by adrwal on 11/3/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>

#include "Fields/Field.h"
#include "Fields/CardField.h"
#include "Card.h"
#include "Player.h"

/*
 * Board class is responsible for managing actions caused by players choices.
 * It performs logic which does not require any user input.
 * Mapping user input to actions is done in Game class.
 */
class Board {
public:
    Board();
    ~Board() = default;

    Player* getCurrentPlayer() const;
    int getNewPosition(Player* player, int steps) const;
    const std::vector<std::shared_ptr<Field>> &getFields() const;
    const std::vector<std::unique_ptr<Player>> &getPlayers() const;
    bool willMoveCrossStart(Player* player, int steps) const;
    int rollDice() const;
    Field* getSteppedOnField() const;

    void setRollDiceSeed(int seed);
    void setCurrentPlayerIndex(int index);
    void pushField(std::shared_ptr<Field> field);
    void pushPlayer(std::unique_ptr<Player> player);
    void movePlayer(int steps);
    void nextPlayer();

    void pushChanceCard(std::unique_ptr<Card> card);
    void pushCommunityChestCard(std::unique_ptr<Card> card);

private:
    int rollDiceSeed = 0;
    std::vector<std::shared_ptr<Field>> fields = {};
    std::vector<std::unique_ptr<Player>> players = {};
    std::vector<std::unique_ptr<Card>> chanceCards = {};
    std::vector<std::unique_ptr<Card>> communityChestCards = {};
    int currentPlayerIndex = 0;
};



#endif //BOARD_H
