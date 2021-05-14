#include "Tetromino.h"
#include "TheGame.h"

// matrix defining all the tetromino pieces and their rotation
char mTetrominoes[PIECES_KINDS][ROTATION][XRANGE][YRANGE] =
        {
                // Square
                {
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}
                        }
                },

// I
                {
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 1}
                        },
                        {
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 1}
                        },
                        {
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        }
                }
                ,
// L
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 1, 0},
                                {1, 1, 1, 0}
                        }
                },
// L mirrored
                {
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 1, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 0, 1, 0}
                        }
                },
// N
                {
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0}
                        }
                },
// N mirrored
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0},
                                {1, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0},
                                {1, 1, 0, 0}
                        }
                },
// T
                {
                        {
                                {0, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 0, 0}
                        },
                        {
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 1, 0}
                        }
                }
        };

//matrix defining every tetromino type and rotation the starting (x,y) coordinate on borad
int mInitPos [PIECES_KINDS][ROTATION][POSITION] =
        {
                /* Square */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* I */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* L */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* L mirrored */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* N */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* N mirrored */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
/* T */
                {
                        {1, -3},
                        {1, -3},
                        {1, -3},
                        {1, -3}
                },
        };

// draws a tetromino
void Tetromino::draw()
{
    int k = 0;
    yOffset += yPos; // if a keyboard hit than updates the y offset
    xOffset += xPos;// if a keyboard hit than updates the x offset
    for(int i = 0; i < YRANGE; i++)
    {
        for (int j = 0; j < XRANGE; j++)
        {
            if(mTetrominoes[piece][rotation][i][j] != 0) {
                gotoxy(board.getInitialX() + getXInitPos(piece, rotation) + j + this->xOffset, board.getInitialY() + getYInitPos(piece, rotation) + i + this->yOffset);
                std::cout << figure;
                this->currX[k] = board.getInitialX() + getXInitPos(piece, rotation) + j + this->xOffset; // saves the block x
                this->currY[k] = board.getInitialY() + getYInitPos(piece, rotation) + i + this->yOffset;// saves the block y
                k++;
                if (k == NUMOFBLOCKS) // if already printed four blocks return
                    return;
            }
        }
    }
}

//gets the leftmost block of tetromino x coordinate
int Tetromino::getLeftmostX()const
{
    int min = currX[0];
    for(int i = 1; i < NUMOFBLOCKS; i++)
        if(currX[i] < min)
            min = currX[i];

    return min;
}

//gets the rightmost block of tetromino x coordinate
int Tetromino::getRightmostX()const
{
    int max = currX[0];
    for(int i = 1; i < NUMOFBLOCKS; i++)
        if(currX[i] > max)
            max = currX[i];

    return max;
}

// the function returns 1 if the specific block in the tetromino matrix is filled
int Tetromino::getSquareType(int pPiece, int pRotation, int pX, int pY)const
{
    return mTetrominoes[pPiece][pRotation][pX][pY];
}

//deletes the tetromino last position
void Tetromino::clearTetromino()
{
    for(int i = 0; i < NUMOFBLOCKS; i++)
    {
        gotoxy(getCurrX(i), getCurrY(i));
        std::cout << ' ';
    }
}
int Tetromino::getXInitPos(int tPiece, int tRotation)const
{
    return mInitPos[tPiece][tRotation][0];
}
int Tetromino::getYInitPos(int tPiece, int tRotation)const
{
    return mInitPos[tPiece][tRotation][1];
}

// moves the tetromino down the board return true if the piece is stored
bool Tetromino::down()
{
    if(getOffsetY() < Board::getRows()-1)
    {
        if (!isPossible(getXlogicCoord(getOffsetX()),getOffsetY() + 1, getBlockType(), getBlockRotation()))
        {
            storePiece(getXlogicCoord(getOffsetX()), getOffsetY(), getBlockType(), getBlockRotation());
            initOffsetX();
            initOffsetY();
            //draws a new random tetromino
            //TODO: here handle whether to draw a tetromino or bomb
            draw();
            return true;
        } else {
            clearTetromino();
            yOffset++;
            draw();
            return false;
        }
    }
    else
    {
        storePiece(getXlogicCoord(getOffsetX()),getOffsetY(), getBlockType(),getBlockRotation());
        //draws a new random tetromino
        initOffsetX();
        initOffsetY();
        //TODO: here handle whether to draw a tetromino or bomb
        draw();
        return true;
    }
}

void Tetromino::move(int dir)
{
    switch (dir) {
        case Board::LEFT_KEY :
            xOffset--;
            moveLeftRight(-1);
            down();
            break;
        case Board::RIGHT_KEY :
            xOffset++;
            moveLeftRight(1);
            down();
            break;
        case Board::ROTATE_CLOCKWISE :
            rotation++;
            rotate(1);
            down();
            break;
        case Board::ROTATE_COUNTERCLOCKWISE:
            rotate(-1);
            down();
            break;
        case Board::DROP:
            dropIt();
            break;
    }
}

void Tetromino::moveLeftRight(int newOffset) {
    if (getLeftmostX() > (board.getInitialX() + 1)) {
        if(getRightmostX() < (board.getInitialX() + Board::cols + 1)) {
            if (isPossible(getXlogicCoord(getOffsetX()) + newOffset, getOffsetY(), getBlockType(),
                           getBlockRotation())) {
                xOffset += newOffset;
                clearTetromino();
                draw();
            }
        }
    }
}

void Tetromino::rotate(int newOffset) {
    if(isPossible(getXlogicCoord(getOffsetX()), getOffsetY(), getBlockType(), (getBlockRotation() + newOffset) % ROTATION)) {
        rotation = (rotation + newOffset) % ROTATION;
        clearTetromino();
        draw();
    }
}

void Tetromino::dropIt() {
    while(!down())
        Sleep(1);
}

int Tetromino::getXlogicCoord(int console_x_offset)const
{
    return (console_x_offset + 4);
}

void Tetromino::init(int kind, int rotate) {
    setPiece(kind);
    setRotation(rotate);
}

void Tetromino::keyboardHit(int dir)
{
    move(dir);
    board.deletePossibleLines();
}

const int Tetromino::getNumBoard() const {
    return numBoard;
}

// TODO : NEED TO ADD CHECKING OF X BORDERS
bool Tetromino::isPossible(int pivX, int pivY, int pPiece, int pRotation)const
{
    // This is just to check the 4x4 blocks of a piece with the appropriate area in the board
    for (int i1 = pivX, i2 = 0; i1 < pivX + NUMOFBLOCKS; i1++, i2++)
    {
        for (int j1 = pivY - MATRIX_Y_OFFSET, j2 = 0; j1 < (pivY - MATRIX_Y_OFFSET)  + NUMOFBLOCKS ; j1++, j2++)
        {
            if(j1 >= 0)
                if ((getSquareType(pPiece, pRotation,j2,i2) != 0)  && !board.isFreeBlock(i1,j1) )
                    return false;
            // Check if the piece have collision with a block already stored in the map
        }
    }
    // No collision
    return true;
}

int Tetromino::storePiece(int pivX, int pivY, int pPiece, int pRotation)
{
    int counter = 0;
    int bottomLineCounter = 0;

    for (int i1=pivX,i2 = 0; i1 < pivX+ NUMOFBLOCKS ;i1++,i2++) {
        for (int j1 = pivY-MATRIX_Y_OFFSET,j2 = 0; j1 < (pivY-MATRIX_Y_OFFSET) +NUMOFBLOCKS; j1++,j2++) {
            if(j1 >= 0){
                if ( getSquareType(pPiece, pRotation,j2,i2) != 0 ){
                    if(j1 == pivY)
                        bottomLineCounter++;

                    board.setBoardPosition(i1, j1);
                    counter++;
                }
                if(counter == NUMOFBLOCKS)
                    return bottomLineCounter;
            }
        }
    }
    return -1;
}

void Tetromino::deletePiece(int pivX, int pivY, int pPiece, int pRotation)
{
    int counter = 0;
    for (int i1=pivX,i2 = 0; i1 < pivX+ NUMOFBLOCKS ;i1++,i2++)
    {
        for (int j1 = pivY-MATRIX_Y_OFFSET,j2 = 0; j1 < (pivY-MATRIX_Y_OFFSET) +NUMOFBLOCKS; j1++,j2++)
        {
            if(j1 >= 0)
            {
                if ( getSquareType(pPiece, pRotation,j2,i2) != 0 )
                {
                    board.resetBoardPosition(i1, j1);
                    counter++;
                }
                if(counter == NUMOFBLOCKS)
                    return;
            }
        }
    }
}

// TODO : ADD 1 point for each block you store in the 1 line so in case we dont complete any line we will have point to go to
// find the best final position of the specific Tetromino in his board ( the final position that gaines the biggest score value )
void Tetromino::FindBestPos()
{
    int max_score = 0,score = 0, bottom_squars = 0;


    for(int y = Board::rows ; y >= 1  ; y--)
    {
        for(int x = 0; x < Board::cols ; x++)             // run over Board columns
        {
            for( int r = 0  ; r < ROTATION ; r++ )       // check all the possible rotations
            {

                if ( isPossible(x,y,piece,r) )
                {
                    bottom_squars = storePiece(x, y, piece, r);      // set only for check the value of score
                    score = board.FindPosScore() + bottom_squars;   // get the score gained in the last set of Tetromino

                    // if it is the max score so save the position
                    if (score >= max_score)
                    {
                        best_x = x;
                        best_r = r;
                        max_score = score;
                    }
                    deletePiece(x, y, piece, r);    // after we check the score, delete the piece from the last position so we can check the next position
                }
            }
        }
    }
}

void Tetromino::setFigure(char figure) {
    Tetromino::figure = figure;
}

//  Tetromino move Wisely towards the best possible position
void Tetromino::moveWiseStep()
{
    if (rotation < best_r) {                     // rotate clock wise
        rotation = (rotation+1)%ROTATION;
        rotate(1);
    }
    else if (xPos > best_x) {                    // move left
        --xPos;
        moveLeftRight(-1);
    }
    else if (xPos < best_x ) {                   // move right
        ++xPos;
        moveLeftRight(1);
    }
    else if (xPos == best_x && rotation == best_r) {
        dropIt();                                // drop Tetromino
    }
    down();
    Sleep(700);
}

void Tetromino::moveRandomStep()
{
    int randKey = rand()%5 + 1;
    switch (randKey)
    {
        case 1 :
            --xPos;
            moveLeftRight(-1);
        case 2 :
            ++xPos;
            moveLeftRight(1);
        case 3 :
            ++rotation;
            rotate(1);
        case 4 :
            --rotation;
            rotate(-1);
        case 5 :
            dropIt();
        default :
            break;
    }
}
