#include "TheGame.h"

void TheGame::init()
{
    board[0].setArrowKeys("adswx");
    board[1].setArrowKeys("jlkim");
    TheGame::menu();
}

void TheGame::run()
{
    char key = 0;
    int dir;
    do{
        if(_kbhit())
        {
            key = getchar();

        }

    } while (key != ESC);
    setTextColor(Color::WHITE);
    clear_screen();
}

void TheGame::menu()
{

}
