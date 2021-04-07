#include "TheGame.h"

void TheGame::init()
{
    board[0].setArrowKeys("adswx");
    board[1].setArrowKeys("jlkim");
    menu(false);
}

void TheGame::start_new()
{
    clear_screen();
    board->draw();
    board[0].init();
    board[1].init();
    board[0].start(); // TODO: initialization of the piece in the center of the screen
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
    char act = 0;
    cout << "Tetris - Main Menu:\n" << "(1) Start a new game" << endl;
    if (Paused)
        cout << "(2) Continue a paused game " << endl;
    cout << "(8) Present instructions and keys\n" << "(9) EXIT" << endl;

    act = (char) _getch();

    while (act != EXIT) {
        if (act == NEW_GAME) {                                          // initialize new game
            this->start_new();
        } else if (act == CONTINUE_GAME) {                              // continue paused game
            if (Paused)
                this->resume();
        } else if (act == KEYS_INSTRUCTIONS) {                          // print keys and instructions
            cout
                    << "Each player can move the pieces to the: left / right / down or to rotate the pieces in clockwise direction or counterclockwise direction:\ngame is over if your pieces reach the top of the screen, and you can only remove pieces from the screen by filling all the blank space in a line. "
                    << endl;
            cout << "Keys:\n"
                    "                               Left Player                Right Player\n"
                    "LEFT:                            a or A                     j or J\n"
                    "RIGHT:                           d or D                     l (small L) or L\n"
                    "ROTATE clockwise:                s or S                     k or K\n"
                    "ROTATE counterclockwise:         w or W                     i or I (uppercase i)\n"
                    "DROP:                            x or X                     m or M\n" << endl;

            cout << "Please press ESC to return to the main menu" << endl;

            while( act != ESC )
                act = (char) _getch();
        }
        clear_screen();
        cout << "Tetris - Main Menu:\n" << "(1) Start a new game" << endl;
        if (Paused)
            cout << "(2) Continue a paused game " << endl;
        cout << "(8) Present instructions and keys\n" << "(9) EXIT" << endl;
        act = (char) _getch();
    }
    this->exit();
}

int TheGame::random(int compare)
{
    return (rand() % compare);
}

void TheGame::exit()
{
    clear_screen();
    std::cout << "Thank you!" << std::endl;
    Sleep(2000);
}

void TheGame::resume()
{
    //TODO:
}
