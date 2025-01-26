//
// Created by adrwal on 11/17/24.
//

#ifndef BOARDSETUPPER_H
#define BOARDSETUPPER_H


class Board;

class BoardSetupCreator {
public:
    static void createClassicBoard(Board& board);
private:
    void initCards(Board& board);
};



#endif //BOARDSETUPPER_H
