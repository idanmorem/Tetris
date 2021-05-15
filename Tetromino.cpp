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
        if (!isPossible(0,1,0))
        {
            storePiece(getOffsetX(), getOffsetY(), getBlockType(), getBlockRotation());
            return true; // if stored
        } else {
            clearTetromino();
            yOffset++;
            draw();
            return false;
        }
    }
    else
    {
        storePiece(getOffsetX(),getOffsetY(), getBlockType(),getBlockRotation());
        return true; //if stored
    }
}

void Tetromino::move(int dir)
{
    switch (dir) {
        case Board::LEFT_KEY :
            moveLeftRight(-1);
//            if(down())
//            {
//                init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//                draw();
//            }
            break;
        case Board::RIGHT_KEY :
            moveLeftRight(1);
//            if(down())
//            {
//                init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//                draw();
//            }
            break;
        case Board::ROTATE_CLOCKWISE :
            rotate(1);
//            if(down())
//            {
//                init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//                draw();
//            }
            break;
        case Board::ROTATE_COUNTERCLOCKWISE:
            rotate(-1);
//            if(down())
//            {
//                init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//                draw();
//            }
            break;
        case Board::DROP:
            dropIt();
//            init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//            draw();
            break;
    }
}

void Tetromino::moveLeftRight(int newOffset) {
    if (getLeftmostX() > (board.getInitialX())) {
        if(getRightmostX() < (board.getInitialX() + Board::cols)) {
            if (isPossible(newOffset, 0, 0)) {
                xOffset += newOffset;
                clearTetromino();
                draw();
            }
        }
    }
}

void Tetromino::rotate(int newOffset) {
    if(isPossible(0, 0, newOffset)) {
        rotation = (rotation + newOffset) % ROTATION;
        clearTetromino();
        draw();
    }
}

void Tetromino::dropIt() {
    while(!down())
        Sleep(1);
}

void Tetromino::init(int kind, int rotate) {
    initOffsetX();
    initOffsetY();
    setPiece(kind);
    setRotation(rotate);
}

//void Tetromino::keyboardHit(int dir)
//{
//    move(dir);
//    if(down())
//    {
//        if(TheGame::random(20) == 0)
//        {
//
//        }
//        init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
//        draw();
//        board.deletePossibleLines();
//    }
//
//}
//
//const int Tetromino::getNumBoard() const {
//    return numBoard;
//}

bool Tetromino::isPossible(int newXoffset, int newYoffset, int newRotateOffset)const
{
    // This is just to check the 4x4 blocks of a piece with the appropriate area in the board
    for (int i1 = xOffset + newXoffset, i2 = 0; i1 < xOffset + newXoffset + NUMOFBLOCKS; i1++, i2++)
    {
        for (int j1 = yOffset + newYoffset - MATRIX_Y_OFFSET, j2 = 0; j1 < (yOffset + newYoffset - MATRIX_Y_OFFSET)  + NUMOFBLOCKS ; j1++, j2++)
        {
            if(j1 >= 0)
                if ((getSquareType(piece, (rotation + newRotateOffset) % ROTATION,j2,i2) != 0)  && !board.isFreeBlock(i1,j1) )
                    return false;
            // Check if the piece have collision with a block already stored in the map
        }
    }
    // No collision
    return true;
}

void Tetromino::storePiece(int pivX, int pivY, int pPiece, int pRotation)
{
    int counter = 0;
    for (int i1=pivX,i2 = 0; i1 < pivX+ NUMOFBLOCKS ;i1++,i2++) {
        for (int j1 = pivY-MATRIX_Y_OFFSET,j2 = 0; j1 < (pivY-MATRIX_Y_OFFSET) +NUMOFBLOCKS; j1++,j2++) {
            if(j1 >= 0){
                if ( getSquareType(pPiece, pRotation,j2,i2) != 0 ){

                    board.setBoardPosition(i1, j1);
                    counter++;
                }
                if(counter == NUMOFBLOCKS)
                    return;
            }
        }
    }
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

// find the best final position of the specific Tetromino in his board ( the final position that gaines the biggest score value )
void Tetromino::FindBestPos()
{
    int line_before = 0,line_after = 0,added = 0, max_added = 0;
    for(int y=Board::rows-1; y >= 1 ;y--)
    {
        for (int x = 0; x < Board::cols; x++)             // run over Board columns
        {
            for (int r = 0; r < ROTATION; r++)// check all the possible rotations
            {
                //TODO:check with snir for OK
                if (isPossible(0, 0, 0)) {
                    line_before = board.lineCounter(y);
                    storePiece(x, y, piece, r);
                    if (board.lineCounter(y) == 12 || board.lineCounter(y - 1) == 12) {
                        best_x = x;
                        best_r = r;
                        deletePiece(x, y, piece, r);
                        return;
                    } else
                    {
                        line_after = board.lineCounter(y);
                        added = line_after - line_before;
                        if (max_added < added)
                        {
                            max_added = added;
                            best_x = x;
                            best_r = r;
                        }
                        deletePiece(x, y, piece, r);
                    }
                }
            }
        }
    }
}

//void Tetromino::setFigure(char figure) {
//    Tetromino::figure = figure;
//}

//  Tetromino move Wisely towards the best possible position
void Tetromino::moveWiseStep()
{
    if (rotation != best_r) {                     // rotate clock wise
        rotate(1);
        if(down())
        {
            init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
            draw();
        }
    }
    else if (xOffset > best_x) {                    // move left
        moveLeftRight(-1);
        if(down())
        {
            init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
            draw();
        }
    }
    else if (xOffset < best_x ) {                   // move right
        moveLeftRight(1);
        if(down())
        {
            init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
            draw();
        }
    }
    else if (xOffset == best_x && rotation == best_r) {
        dropIt();
        init(TheGame::random(PIECES_KINDS), TheGame::random(ROTATION));
        draw();// drop Tetromino
    }
    Sleep(200);
}

void Tetromino::moveRandomStep()
{
    int randKey = rand()%5 + 1;
    switch (randKey)
    {
        case 1 :
            moveLeftRight(-1);
        case 2 :
            moveLeftRight(1);
        case 3 :
            rotate(1);
        case 4 :
            rotate(-1);
        case 5 :
            dropIt();
        default :
            break;
    }
}
