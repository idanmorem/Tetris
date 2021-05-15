#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Menu.h"
#include "Board.h"
#include "Bomb.h"
#include "IO.h"
#include "Tetromino.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include <conio.h>
#include <cstdlib>
#include <string>

#define PLAYERS 2

class TheGame{
    Board board[2];
    Tetromino t[2]{{0, (char)254, board[0]}, {1, (char)254, board[1]}};
//    Tetromino t1{1, (char)254, board[1]};
    Bomb b[2]{{0, 'X', board[0]}, {1, 'X', board[1]}};
//    Bomb b1{1, 'X', board[1]};
    ComputerPlayer c0{board[0],t[0], b[0]};
    ComputerPlayer c1{board[1],t[1], b[1]};
    HumanPlayer h0{board[0],t[0], b[0]};
    HumanPlayer h1{board[1],t[1], b[1]};
    Player* players[PLAYERS] = {&c0,&c1};
    bool paused = false;

    int over = 0;
//    char type = 0;
    bool drop[2] = {false,false};
    void startNew(char type);
    void resume();
    static void exitGame();
    void activate();

public:
    static constexpr char newGameHvsH = '1';
    static constexpr char newGameHvsC = '2';
    static constexpr char newGameCvsC = '3';
    static constexpr char continueGame = '4';
    static constexpr char keysInstructions = '8';
    static constexpr char exit = '9';
    enum {ESC = 27};
    enum {CONTINUE, PLAYER0, PLAYER1, TIE};
    static int random(int limit);
    void run();
    void gameLoop();
    static void clearKeyboardBuffer();
    void waitForKey(char key);
    void init();
    bool checkGameStatus();
    void setPaused(bool paused);
    bool whichObj(int i);
};

#endif //TETRIS_THEGAME_H