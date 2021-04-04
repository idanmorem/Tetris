#include "TheGame.h"

void TheGame::init()
{
    board[0].setArrowKeys("adswx");
    board[1].setArrowKeys("jlkim");
    menu(false);
}

void TheGame::start_new()
{
    board[0].init();
    board[1].init();
    board[0].start(random(PIECES_KINDS)); // TODO: initialization of the piece in the center of the screen
    char key = 0;
    int dir;
    do{
        if(_kbhit())
        {
            key = _getch();
            if((dir = board[0].getDirection(key)) != -1)
                board[0].setDirection(dir);
            else if((dir = board[1].getDirection(key)) != -1)
                board[1].setDirection(dir);
        }
//        board[0].move();
//        board[1].move();
        Sleep(200);
    } while (key != ESC);

    setTextColor(Color::WHITE);
    clear_screen();
}

void TheGame::menu(bool Paused)
{
    char act = 0 ;
    cout << "Tetris - Main Menu:\n" << "(1) Start a new game" << endl;
    if(Paused)
        cout << "(2) Continue a paused game " << endl ;
    cout << "(8) Present instructions and keys\n" << "(9) EXIT" << endl;

    act = getchar();
    switch(act) {
        case '1':
            this->start_new();            // initialize new game
            break;
        case '2':
            if (Paused)             // continue paused game
                this->resume();
            else
                cout << "Wrong input\n";
            break;
        case '8':                     // print keys and instructions ( !!! need to add instruction !!! )
            cout << "Each player can move the pieces to the : left / right / down or to rotate the pieces in clockwise direction or counterclockwise direction:\n  game is over if your pieces reach the top of the screen, and you can only remove pieces from the screen by filling all the blank space in a line. "<< endl;
            cout << "Keys:\n"
                    "                               Left Player                Right Player\n"
                    "LEFT:                            a or A                     j or J\n"
                    "RIGHT:                           d or D                     l (small L) or L\n"
                    "ROTATE clockwise:                s or S                     k or K\n"
                    "ROTATE counterclockwise:         w or W                     i or I (uppercase i)\n"
                    "DROP:                            x or X                     m or M\n" << endl;
            break;
        case '9':                     // exit game
            this->exit();
            break;

        default:                    // in case of wrong input
            cout << "Wrong input\n";
    }

}

int TheGame::random(int compare)
{
    return (rand() % compare);
}

void TheGame::exit()
{
    clear_screen();
    std::cout << "Thank you!" << std::endl;
}

void TheGame::resume()
{
    //TODO:
}
