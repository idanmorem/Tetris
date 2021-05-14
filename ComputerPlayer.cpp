#include "ComputerPlayer.h"
#include "TheGame.h"

// TODO : ABSORB GAME LEVEL
// return true if the next move should be a random move
bool ComputerPlayer::isWiseMove() const {
    switch (level) {
        case 'a':  // BEST player level
            return true;
        case 'b':{ // GOOD player level
            if (rand() % 40 == 1)
                return false;
            else
                return true;
        }
        case 'c':{     // NOVICE player level
            if (rand() % 10 == 1)
                return false;
            else
                return true;
        }
    }
    return true;
}



void ComputerPlayer::makeTurn() {

    if (t.getOffsetX() == 4 && t.getOffsetY() == 0){         // if Tetromino is at his starting position
        setWise(isWiseMove());                         // check if the next move is wiseMove
        if(wise)                                            // if it wise move, find(and set) the best position and rotation for the Tetromino
            t.FindBestPos();
    }
    if (wise)
        t.moveWiseStep();
    else
        t.moveRandomStep();
}






