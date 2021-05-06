cmake_minimum_required(VERSION 3.17)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris main.cpp Board.cpp Board.h TheGame.cpp TheGame.h Tetromino.cpp Tetromino.h IO.h IO.cpp GameObjects.h GameObjects.cpp Bomb.cpp Bomb.h)