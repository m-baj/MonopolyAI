//
// Created by adrwal on 11/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <vector>

#include "Decision.h"

class Trains;
class Utilities;
class Property;

class Player {
public:
    virtual ~Player() = default;

    Player(const std::string& name, int startMoney)
        : name(name), money(startMoney) {};

    std::string getName() const;
    int getMoney() const;
    int getPositionIdx() const;
    const std::vector<std::shared_ptr<Property>>& getProperties() const;
    const std::vector<std::shared_ptr<Utilities>>& getUtilities() const;
    const std::vector<std::shared_ptr<Trains>>& getTrains() const;
    bool ownsAllPropertiesOf(Color color) const;
    int getNumberOfTrains() const;
    std::vector<PlayerDecisionOutputs> getMadeTurnDecisions() const;

    void setPositionIdx(int positionIdx);
    void pushProperty(std::shared_ptr<Property> property);
    void pushTrain(std::shared_ptr<Trains> train);
    void addMoney(int amount);
    void declareBankruptcy();
    void saveTurnDecision(PlayerDecisionOutputs decision);
    void clearTurnDecisions();

    void payTo(Player* player, int amount);
    void payToBank(int amount);

    virtual std::unique_ptr<DecisionSelector> createDecisionSelector() = 0;

private:
    /*
     * Blocks Game loop. Handles deducing money from player.
     * If player does not have enough money, it handles player's decision to obtain it.
     */
    void pay(int amount, Player* player = nullptr);

    std::vector<std::shared_ptr<Property>> properties = {};
    std::vector<std::shared_ptr<Utilities>> utilities = {};
    std::vector<std::shared_ptr<Trains>> trains = {};
    std::vector<PlayerDecisionOutputs> decisionsMadeThisTurn = {};
    int money;
    std::string name;
    int positionIdx = 0;
    bool isBankrupt = false;
};

class ConsolePlayer final : public Player
{
public:
    ConsolePlayer(const std::string& name, int startMoney)
        : Player(name, startMoney)
    {
    }
    ~ConsolePlayer() override = default;

    std::unique_ptr<DecisionSelector> createDecisionSelector() override;
};

class AiPlayer final : public Player
{
public:
    AiPlayer(const std::string& name, int startMoney)
        : Player(name, startMoney)
    {
    }
    ~AiPlayer() override = default;

    std::unique_ptr<DecisionSelector> createDecisionSelector() override;
};


#endif //PLAYER_H
