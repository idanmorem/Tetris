#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"
#include "Tetromino.h"
#include <conio.h>
#include <cstdlib>
#include <string>

#define PLAYERS 2

class TheGame{
    Board board[2];
    Tetromino t0{0, (char)256, board[0]};
    Tetromino t1{1, (char)256, board[1]};
    bool paused = false;
    int over = 0;
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
    static constexpr char newGame = '1';
    static constexpr char continueGame = '2';
    static constexpr char keysInstructions = '8';
    static constexpr char exit = '9';
    enum {ESC = 27};
    enum {CONTINUE, PLAYER0, PLAYER1, TIE};
    int random(int limit) const;
    void run();
    void gameLoop();
    void clearKeyboardBuffer();
    void waitForKey(char key);
    void init();
    bool checkGameStatus();
};

#endif //TETRIS_THEGAME_H