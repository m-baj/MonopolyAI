//
// Created by adrwal on 11/3/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <vector>
#include "OwnableField.h"
#include "Property.h"


class Player {
public:
    Player(const std::string& name, int startMoney)
        : name(name), money(startMoney) {};

    std::string getName() const;
    int getMoney() const;
    int getPositionIdx() const;
    const std::vector<std::shared_ptr<OwnableField>>& getOwnableFields() const;

    void setPositionIdx(int positionIdx);
    void pushOwnable(std::shared_ptr<OwnableField> ownable);
    void addMoney(int amount);

    void payTo(Player* player, int amount);
    void payToBank(int amount);
    bool ownsAllPropertiesOf(Color color) const;

private:
    void pay(int amount, Player* player = nullptr);

    std::vector<std::shared_ptr<OwnableField>> ownableFields;
    int money;
    std::string name;
    int positionIdx = 0;
};


#endif //PLAYER_H
