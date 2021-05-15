#include "HumanPlayer.h"
#include "TheGame.h"
#include "Tetromino.h"
#include "Board.h"
#include "IO.h"

int HumanPlayer::makeTurn()
{
    stored = false;
    while (true) {
        int key = 0, dir = {Board::KEYS_SIZE};
        while(true)
        {
            if(_kbhit()) {
                key = _getch();
                TheGame::clearKeyboardBuffer();
                if (key == TheGame::ESC) {
                    return -1;
                }
                if ((dir = board.getDirection(key)) != -1) {
                    if(!bombInHand) {
                        t.move(dir);
                        if(t.down()) {
                            stored = true;
                        }
                        return 0;
                    }
                    else
                    {
                        b.move(dir);
                        if(b.down()) {
                            stored = true;
                            bombInHand = false;
                        }
                        return 0;
                    }
                }
            }
            if(!bombInHand)
                t.down();
            else
                b.down();
                Sleep(1000);
                return 0;
        }
    }
}
