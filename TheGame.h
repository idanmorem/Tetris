#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"
#include <conio.h>
#include <cstdlib>
#include <string>

//TODO: instead of define use static constexpr / enum same as line 19

#define NEW_GAME '1'
#define CONTINUE_GAME '2'
#define KEYS_INSTRUCTIONS '8'
#define EXIT '9'
#define PLAYERS 2

class TheGame{
    enum {ESC = 27};
    Board board[2];
    Tetromino tetromino[2];
    //TODO: maybe "paused" not needed as a member
    bool paused = false;
    bool over = false;
    //TODO: maybe "stored" not needed as a member
    bool stored = false;
    bool drop[2] = {false,false};
    //TODO: maybe "esc_hit" not needed as a member
    bool esc_hit = false;
    void printMenu();
    void printInstructions();
    void startNew();
    void resume();
    static void exitGame();
    void menu();
    void down(int numBoard);

public:
    //TODO: check which functions can be private
    void init();
    int random(int limit);
    void run();
    void move(int numBoard, int dir);
    int getXlogicCoord(int console_x_offset)const;
    void gameLoop();
    void clearKeyboardBuffer();
    void printGameOver(int numBoard);
    void keyboardHit(int numBoard, int dir);
    void waitForKey(char key);
    static void moveLeftRight(int numBoard, int move);
    void rotate(int numBoard, int move);
    void dropIt(int numBoard);
};

#endif //TETRIS_THEGAME_H