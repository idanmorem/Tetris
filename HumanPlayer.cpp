#include "HumanPlayer.h"
#include "TheGame.h"
#include "Tetromino.h"
#include "Board.h"
#include "IO.h"

int HumanPlayer::makeTurn()
{
    while (true) {
        int key = 0, dir = {Board::KEYS_SIZE};
        while(dir == Board::KEYS_SIZE )
        {
            if(_kbhit()) {
                key = _getch();
                TheGame::clearKeyboardBuffer();
                if (key == TheGame::ESC) {
                    return -1;
                }
                if ((dir = board.getDirection(key)) != -1) {
                    t.keyboardHit(dir);
                    return 0;
                }
            }
            else
            {
                t.down();
                Sleep(1000);
                return 0;
            }
        }
    }
}
