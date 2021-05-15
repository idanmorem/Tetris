#ifndef TETRIS_COMPUTERPLAYER_H
#define TETRIS_COMPUTERPLAYER_H
#include "Player.h"

// ComputerPlayer.h
class ComputerPlayer: public Player {
    char level = 0;
    bool wise = true;
public:
    using Player::Player; // use the ctor of the base, as is
    int makeTurn() override; // we override the virtual function of the base
    bool isWiseMove() const;
    bool isWise() const {return wise;}
    void setWise(bool _wise) { wise = _wise;}
};

#endif //TETRIS_COMPUTERPLAYER_H
