#ifndef TETRIS_THEGAME_H
#define TETRIS_THEGAME_H

#include "Board.h"
#include "IO.h"
#include "Bomb.h"
#include <conio.h>
#include <cstdlib>
#include <string>

#define PLAYERS 2

class TheGame{
    Board board[2];
    Tetromino t1{board, 256};
    Tetromino t2{board, 256};
    Bomb b1{board, 'X'};
    Bomb b2{board, 'X'};
    GameObjects* objects[2][2] = {{&t1, &t2}, {&b1, &b2}};
    //TODO: maybe "paused" not needed as a member
    bool paused = false;
    bool over = false;
    //TODO: maybe "stored" not needed as a member
    bool stored = false;
    bool drop[2] = {false,false};
    //TODO: maybe "esc_hit" not needed as a member
    bool esc_hit = false;
    void printMenu() const;
    void printInstructions() const;
    void startNew();
    void resume();
    static void exitGame();
    void menu() const;
    void down(int numBoard);
    static void printGameOver(int numBoard);

public:
    static constexpr char newGame = '1';
    static constexpr char continueGame = '2';
    static constexpr char keysInstructions = '8';
    static constexpr char exit = '9';
    enum {ESC = 27};
    int random(int limit) const;
    void run();
    int getXlogicCoord(int console_x_offset)const;
    void gameLoop();
    void clearKeyboardBuffer();
    void keyboardHit(int numBoard, int dir);
    void waitForKey(char key);
    void init();
};

#endif //TETRIS_THEGAME_H