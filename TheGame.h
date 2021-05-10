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
//    IO gameIO;
    Board board[2];
    Tetromino t0{0, (char)256, board[0]};
    Tetromino t1{1, (char)256, board[1]};
//    GameObjects* objects[2][2] = {{&t1, &t2}, {&b1, &b2}};
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
    void menu();
    static void printGameOver(int numBoard);

public:
    static constexpr char newGame = '1';
    static constexpr char continueGame = '2';
    static constexpr char keysInstructions = '8';
    static constexpr char exit = '9';
    enum {ESC = 27};
    int random(int limit) const;
    void run();
    void gameLoop();
    void clearKeyboardBuffer();
    void waitForKey(char key);
    void init();
};

#endif //TETRIS_THEGAME_H