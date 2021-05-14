#include "HumanPlayer.h"
#include "TheGame.h"
#include "Tetromino.h"
#include "Board.h"
#include "IO.h"


void HumanPlayer::makeTurn() {

    while (true) {
        int key = 0, dir = {Board::KEYS_SIZE};
        while(dir == Board::KEYS_SIZE )
        {
            if(_kbhit()) {
                key = _getch();
                TheGame::clearKeyboardBuffer();
                if (key == TheGame::ESC)
                    return;
                if ((dir = board.getDirection(key)) != -1) {
                    t.keyboardHit(dir);
                    return;
                }
            }
            else
            {
                t.down();
                Sleep(1000);
            }
        }
    }
}
