//
// Created by adrwal on 11/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <vector>
#include "OwnableField.h"
#include "Property.h"
#include "Utilities.h"
#include "Trains.h"

class Player {
public:
    Player(const std::string& name, int startMoney, Board& board)
        : name(name), money(startMoney), board(board) {};

    std::string getName() const;
    int getMoney() const;
    int getPositionIdx() const;
    const std::vector<std::shared_ptr<Property>>& getProperties() const;
    const std::vector<std::shared_ptr<Utilities>>& getUtilities() const;
    const std::vector<std::shared_ptr<Trains>>& getTrains() const;

    void setPositionIdx(int positionIdx);
    void pushProperty(std::shared_ptr<Property> property);
    void pushTrain(std::shared_ptr<Trains> train);
    void addMoney(int amount);
    void declareBankruptcy();

    void payTo(Player* player, int amount);
    void payToBank(int amount);
    bool ownsAllPropertiesOf(Color color) const;
    int getNumberOfTrains() const;

private:
    /*
     * Blocks Game loop. Handles deducing money from player.
     * If player does not have enough money, it handles player's decision to obtain it.
     */
    void pay(int amount, Player* player = nullptr);

    std::vector<std::shared_ptr<Property>> properties = {};
    std::vector<std::shared_ptr<Utilities>> utilities = {};
    std::vector<std::shared_ptr<Trains>> trains = {};
    int money;
    std::string name;
    int positionIdx = 0;
    Board& board;
    bool isBankrupt = false;
};


#endif //PLAYER_H
