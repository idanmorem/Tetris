#include "ComputerPlayer.h"
#include "TheGame.h"


int ComputerPlayer::makeTurn() {

    switch (this->level)
    {
        case 'a':  // BEST player level
            return ExactMove();
        case 'b':{  // GOOD player level
            if (40 != rand()%40 +1)
                return ExactMove();
            else
                return RandMove();
        }
        case 'c':{     // NOVICE player level
            if ( 10 != rand()%10 +1)
                return ExactMove();
            else
                return RandMove();
        }
    }
    return -1;
}

int ComputerPlayer::ExactMove() {

    t.FindBestPos();
    //if possiblePath - save the path
    //make the path moves
    return -1; //TEST ONLY
}

int ComputerPlayer::RandMove() const {
    return -1; //TEST ONLY
}