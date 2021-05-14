#ifndef TETRIS_HUMANPLAYER_H
#define TETRIS_HUMANPLAYER_H
#include "Player.h"

// HumanPlayer.h
class HumanPlayer: public Player {
public:
    using Player::Player; // use the ctor of the base, as is
    void makeTurn() override; // we override the virtual function of the base
    void WaitForInput();
};


#endif //TETRIS_HUMANPLAYER_H
