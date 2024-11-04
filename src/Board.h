//
// Created by adrwal on 11/3/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <vector>

#include "Field.h"
#include "Player.h"


class Board {
public:

private:
    // TODO: maybe change to other data type
    std::vector<std::shared_ptr<Field>> fields;
    std::vector<std::unique_ptr<Player>> players;

};



#endif //BOARD_H
