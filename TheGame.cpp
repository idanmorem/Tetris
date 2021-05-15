#include "TheGame.h"

//initialize game
void TheGame::init()
{
    char playerKeys[PLAYERS][Board::KEYS_SIZE + 1] = {"adswx", "jlkim"};
    for(int i = 0; i < PLAYERS; i++)
    {
        board[i].setNumBoard(i);
        board[i].setArrowKeys(playerKeys[i]);
        board[i].setInitialX(20+i*33);
        board[i].setStartBoard(board[i].getInitialX()+4);
    }
    activate();
}

//start new game
void TheGame::startNew(char type)
{
    char lvl;
    over = false;
    if( type != newGameHvsH )
    {
        Menu::printRequestPcLevel();
        lvl = (char)_getch();
    }
    clearScreen();
    for(int i = 0; i < PLAYERS; i++) {
        board[i].drawBoardLimits();
        board[i].setEmpty();
    }
    switch(type)
    {
        case newGameHvsH :
            players[0] = &h0;
            players[1] = &h1;
            break;
        case newGameHvsC :
            players[0] = &h0;
            players[1] = &c1;
            break;
        case newGameCvsC :
            players[0] = &c0;
            players[1] = &c1;
            break;
        default:
            break;
    }
    run();
}

//main menu of the game
void TheGame::activate() {
    clearScreen();
    Menu::printMenu(paused);
    char act = (char)getchar();
    while ( act != exit) {
        switch (act) {
            case newGameHvsH :            // start new game Human vs Human
                startNew(newGameHvsH);
                break;
            case newGameHvsC :            // start new game Human vs Computer
                startNew(newGameHvsC);
                break;
            case newGameCvsC :            // start new game  Computer vs Computer
                startNew(newGameCvsC);
                break;
            case continueGame :            // continue paused game
                if (paused)
                    resume();
                break;
            case keysInstructions :
                Menu::printInstructions();        // print keys and instructions
                waitForKey(ESC);
                break;
        }
        clearScreen();
        Menu::printMenu(paused);
        act = (char)_getch();
    }
    exitGame();
}

//waiting for the key
void TheGame::waitForKey(char key)
{
    char act = (char) _getch();
    while( act != key )
        act = (char) _getch();
}

//exit game
void TheGame::exitGame()
{
    clearScreen();
    std::cout << "Thank you!" << std::endl;
    while(!_getch())
        Sleep(200);
}

//resume paused game
void TheGame::resume()
{
    clearScreen();                                     // clear the screen
    for(int i = 0; i < PLAYERS; i++) {
        board[i].drawBoardLimits();                                   // draw 2 game boards
        board[i].updateScreen();                    // update left board to be as it was before the game was paused
    }
    run();                                        // run the game again
}

// generic random function return number between 0 to the parameter "compare"
int TheGame::random(int limit)
{
    return (rand() % limit);
}

// run the game by using _kbhit() and _getch()
void TheGame::run()
{
    //draws a new random tetromino
    if(!paused) {
        t[0].init(random(PIECES_KINDS), random(ROTATION));
        t[1].init(random(PIECES_KINDS), random(ROTATION));
    }
    t[0].draw();
    t[1].draw();
    Sleep(300); //TEST
    gameLoop();
    paused = !over;   // set "paused" val according to current game status
}

void TheGame::clearKeyboardBuffer()
{
    int junk;
    while (_kbhit())
    {
        junk = _getch();
        if(junk == ESC) {
            return;
        }
    }
    fflush(NULL);
}

// the main game loop that keeps on until the game is finished
void TheGame::gameLoop() {
    while (true) {
        for(int i = 0; i < PLAYERS; i++) {
            if(whichObj(i))
                break;
        }
        if (checkGameStatus())
            return;
    }
}

bool TheGame::whichObj(int i)
{
    if(players[i]->makeTurn() == -1) {
        setPaused(true);
        return true;
    }
    else
    {
        if(players[i]->isStored())
        {
            if(random(20) == 0) {
                players[i]->setBombInHand(true);
                b[i].init(-1, -1);
                b[i].draw();
            }
            else
            {
                t[i].init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
                t[i].draw();
            }
        }
        board[i].deletePossibleLines();
    }
    return false;
}

// checks if the game is over/tie/continue
bool TheGame::checkGameStatus(){
    for(int i = 0; i < PLAYERS; i++)
    {
        if(board[i].isGameOver())
            over += (i+1);
    }
    switch (over){
        case CONTINUE:
            return false;
        case PLAYER0:
            Menu::printGameOver(0);
            return true;
        case PLAYER1:
            Menu::printGameOver(1);
            return true;
        case TIE:
            Menu::printTie();
            return true;
    }
    return false;
}

void TheGame::setPaused(bool paused) {
    TheGame::paused = paused;
}
