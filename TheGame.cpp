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
    menu();
}

//start new game
void TheGame::startNew()
{
    over = false;
    clearScreen();
    for(int i = 0; i < PLAYERS; i++) {
        board[i].drawBoardLimits();
        board[i].setEmpty();
        tetromino[i].initOffsetX();
        tetromino[i].initOffsetY();
    }
    run();
}

//main menu of the game
void TheGame::menu() const
{
    clearScreen();
    printMenu();
    char act = _getch();
    while (act != exit) {
        if (act == newGame) {                                          // initialize new game
            startNew();
        } else if (act == continueGame) {                              // continue paused game
            if (paused)
                resume();
        } else if (act == keysInstructions) {                          // print keys and instructions
                printInstructions();
                waitForKey(ESC);
        }
        clearScreen();
        printMenu();
        act = (char) _getch();
    }
    exitGame();
}

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
        Sleep(20);
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

int TheGame::getXlogicCoord(int console_x_offset)const
{
    return (console_x_offset + 4);
}

// generic random function return number between 0 to the parameter "compare"
int TheGame::random(int limit) const
{
    return (rand() % limit);
}

// moves the tetromino down the board
//TODO: think how to do it more OOP
//      1) board, tetromino - "drop and check" (this should include clear and draw)
//      2) above returned "hit" (ground or stored tetromino) - store the current tetromino and create the next
void TheGame::down(int numBoard)
{
    if(this->tetromino[numBoard].getOffsetY() < board[numBoard].getRows()-1)
    {
        if (!board[numBoard].isPossible(getXlogicCoord(tetromino[numBoard].getOffsetX()),tetromino[numBoard].getOffsetY() + 1, tetromino[numBoard].getBlockType(),tetromino[numBoard].getBlockRotation()))
        {
            board[numBoard].storePiece(getXlogicCoord(tetromino[numBoard].getOffsetX()),tetromino[numBoard].getOffsetY(), tetromino[numBoard].getBlockType(),tetromino[numBoard].getBlockRotation());
            stored = true;
            drop[numBoard] = false;
            tetromino[numBoard].initOffsetX();
            tetromino[numBoard].initOffsetY();
            //draws a new random tetromino
            tetromino[numBoard].draw(0, 0, tetromino[numBoard].setPiece(random(PIECES_KINDS)),tetromino[numBoard].setRotation(random(ROTATION)), numBoard);
        } else {
            clearTetromino();
            tetromino[numBoard].draw(0, 1, tetromino[numBoard].getBlockType(), tetromino[numBoard].getBlockRotation(),numBoard);
            if(drop[numBoard])
                Sleep(1);
            else
                Sleep(400); // TEST
        }
    }
    else
    {
        board[numBoard].storePiece(getXlogicCoord(tetromino[numBoard].getOffsetX()),tetromino[numBoard].getOffsetY(), tetromino[numBoard].getBlockType(),tetromino[numBoard].getBlockRotation());
        stored = true;
        drop[numBoard] = false;
        //draws a new random tetromino
        tetromino[numBoard].initOffsetX();
        tetromino[numBoard].initOffsetY();
        tetromino[numBoard].draw(0, 0, tetromino[numBoard].setPiece(random(PIECES_KINDS)),tetromino[numBoard].setRotation(random(ROTATION)), numBoard);
    }
}

void TheGame::gameLoop()
{
    int key = 0, dir = 0;
    while (!over) {
        esc_hit = false;
        //TODO: allow input from both players in a single game clock iteration
        if(_kbhit()) {
            key = _getch();
            clearKeyboardBuffer();
            if(esc_hit || (key == ESC))
                return;
            if ((dir = board[0].getDirection(key)) != -1 && !drop[0])
                keyboardHit(0, dir);
            else if ((dir = board[1].getDirection(key)) != -1 && !drop[1])
                keyboardHit(1, dir);
        }
        //TODO: try to remove the need for "stored" bool by handling it inside down() function
        //      the idea is on hit to replace the current tetromino with the next one
        if(!stored) {
            if(!drop[1])
                down(0);
            if(!drop[0])
                down(1);
        }
        stored = false;

        over = board[0].isGameOver();
        //TODO: loop for both boards with: if( board[i].isGameOver() ) over += (i+1);
        //      over would be int indicating: 0) continue 1) player 0 lost, 2) player 1 lost, 3) tie
        //      check outside the loop the value of "over"
        board[0].deletePossibleLines();
        if(over){
            printGameOver(0);
            return;
        }
        over = board[1].isGameOver();
        board[1].deletePossibleLines();
        if(over){
            printGameOver(1);
            return;
        }
    }
}

//TODO: this function should be in class Board or even better in Tetromino with the name "move"
void TheGame::keyboardHit(int numBoard, int dir)
{
    move(numBoard,dir);
    over = board[numBoard].isGameOver();
    board[numBoard].deletePossibleLines();
}

// run the game by using _kbhit() and _getch()
void TheGame::run()
{
    //draws a new random tetromino
    //TODO: should be draw() and the init of tetromino should be in a separated function
    t1.setPiece(random(PIECES_KINDS));
    t1.setRotation(random(ROTATION));
    t1.draw(0, 0, 0);
    tetromino[1].draw(0, 0, tetromino[1].setPiece(random(PIECES_KINDS)), tetromino[1].setRotation(random(ROTATION)), 1);
    gameLoop();
    paused = !over;   // set "paused" val according to current game status
}

void TheGame::printGameOver(int numBoard)
{
    int junk;
    clearScreen();
    if (numBoard == 0)
        std::cout << "Player right won!";
    else
        std::cout << "Player left won!";
    std::cout << '\n';
    std::cout << "Press any key to continue";
    fflush(NULL);
    junk = _getch();
    //    Sleep(500);
}

void TheGame::clearKeyboardBuffer()
{
    int junk;
    while (_kbhit())
    {
        junk = _getch();
        if(junk == ESC) {
            esc_hit = true;
            return;
        }
    }
    fflush(NULL);
}

void TheGame::printMenu() const
{
    cout << "Tetris - Main Menu:\n" << "(1) Start a new game" << endl;
    if (paused)
        cout << "(2) Continue a paused game " << endl;
    cout << "(8) Present instructions and keys\n" << "(9) EXIT" << endl;
}

void TheGame::printInstructions() const
{
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
}