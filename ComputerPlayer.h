#ifndef TETRIS_COMPUTERPLAYER_H
#define TETRIS_COMPUTERPLAYER_H
#include "Player.h"

// ComputerPlayer.h
class ComputerPlayer: public Player {
    char level = 0;

public:
    using Player::Player; // use the ctor of the base, as is
    int makeTurn() override; // we override the virtual function of the base
    int ExactMove() ; // playing the best possible move
    int RandMove() const; // playing the random possible move

};

#endif //TETRIS_COMPUTERPLAYER_H
