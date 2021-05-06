#ifndef TETRIS_BOMB_H
#define TETRIS_BOMB_H

#include "GameObjects.h"

class Bomb : public GameObjects {
    int currX = 4 , currY = 0;
public:
    using GameObjects::GameObjects;
    int getCurrX()const {return this->currX;}
    int getCurrY()const {return this->currY;}
    void activeBomb();
    bool inBombRadius(int i, int j) const;
};

#endif //TETRIS_BOMB_H