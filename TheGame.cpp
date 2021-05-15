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
void TheGame::menu() {
    clearScreen();
    printMenu();
    char act = (char)getchar(); //TEST ONLY
//    char act = (char)_getch();
    char lvl = 0;
    while ( act != exit) {
        switch (act) {
            case newGameHvsH :            // start new game Human vs Human
                setType(newGameHvsH);
                startNew();
                break;
            case newGameHvsC :            // start new game Human vs Computer
                setType(newGameHvsC);
                std::cout << " Please enter Computer game level \n(a) - Best\n(b) - Good\n(c) - Novice"<< std::endl;
                startNew();
                break;
            case newGameCvsC :            // start new game  Computer vs Computer
                setType(newGameCvsC);
                std::cout << " Please enter Computer game level \n(a) - Best\n(b) - Good\n(c) - Novice"<< std::endl;
                startNew();
                break;
            case continueGame :            // continue paused game
                if (paused)
                    resume();
                break;
            case keysInstructions :
                printInstructions();        // print keys and instructions
                waitForKey(ESC);
                break;
            default:
                break;
        }
        clearScreen();
        printMenu();
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

// generic random function return number between 0 to the parameter "compare"
int TheGame::random(int limit)
{
    return (rand() % limit);
}

/*
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
                t0.keyboardHit(dir);
            else if ((dir = board[1].getDirection(key)) != -1 && !drop[1])
                t1.keyboardHit(dir);
        }
        //TODO: try to remove the need for "stored" bool by handling it inside down() function
        //      the idea is on hit to replace the current tetromino with the next one
        if(!stored) {
            if(!drop[1])
                t0.down();
            if(!drop[0])
                t1.down();
            Sleep(400);
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
*/

// run the game by using _kbhit() and _getch()
void TheGame::run()
{
    //draws a new random tetromino
    t0.init(random(PIECES_KINDS), random(ROTATION));
    t1.init(random(PIECES_KINDS), random(ROTATION));
    t0.draw();
    t1.draw();
    Sleep(2000); //TEST
    gameLoop();
    paused = !over;   // set "paused" val according to current game status
}

// prints game over depends on the numBoard
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
            return;
        }
    }
    fflush(NULL);
}

// prints the menu
void TheGame::printMenu() const
{
    cout << "Tetris - Main Menu:\n";
    cout << "(1) Start a new - game Human vs Human\n";
    cout << "(2) Start a new - game Human vs Computer\n";
    cout << "(3) Start a new - game Computer vs Computer\n";
    if (paused)
        cout << "(4) Continue a paused game\n";
    cout << "(8) Present instructions and keys\n";
    cout <<"(9) EXIT" << endl;
}

//prints the instructions
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

// the main game loop that keeps on until the game is finished
void TheGame::gameLoop() {
    while (true) {
        if(players[0]->makeTurn() == -1) {
            setPaused(true);
            break;
        }

        if(players[1]->makeTurn() == -1) {
            setPaused(true);
            break;
        }
        if (checkGameStatus())
            return;
    }
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
            printGameOver(0);
            return true;
        case PLAYER1:
            printGameOver(1);
            return true;
        case TIE:
            printTie();
            return true;
    }
    return false;
}

void TheGame::printTie()
{
    int junk;
    clearScreen();
    std::cout << "We have a tie!";
    std::cout << '\n';
    std::cout << "Press any key to continue";
    fflush(NULL);
    junk = _getch();
    //    Sleep(500);
}

void TheGame::setPaused(bool paused) {
    TheGame::paused = paused;
}
