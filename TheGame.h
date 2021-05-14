#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
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
    Tetromino t0{0, (char)254, board[0]};
    Tetromino t1{1, (char)254, board[1]};
    // Players - TODO: NEED TO CHECK HOW TO KNOW WHICH PLAYERS TO MAKE
    ComputerPlayer c0{board[0],t0};
    ComputerPlayer c1{board[1],t1};

    HumanPlayer h0{board[0],t0};
    HumanPlayer h1{board[1],t1};

    Player* players[PLAYERS] = {&c0,&c1};
    bool paused = false;
    int over = 0;
    char type = 0;
    bool drop[2] = {false,false};
    void printMenu() const;
    void printInstructions() const;
    void startNew();
    void resume();
    static void exitGame();
    void menu();
    static void printGameOver(int numBoard);
    static void printTie();

public:
    static constexpr char newGameHvsH = '1';
    static constexpr char newGameHvsC = '2';
    static constexpr char newGameCvsC = '3';
    static constexpr char continueGame = '4';
    static constexpr char keysInstructions = '8';
    static constexpr char exit = '9';
    enum {ESC = 27};
    enum {CONTINUE, PLAYER0, PLAYER1, TIE};
    int random(int limit) const;
    void run();
    void gameLoop();
    static void clearKeyboardBuffer();
    void waitForKey(char key);
    void init();
    bool checkGameStatus();
    char getType() const {return type;}
    void setType(char gameType) { type = gameType; }
};

#endif //TETRIS_THEGAME_H