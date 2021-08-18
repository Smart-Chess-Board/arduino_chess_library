#ifndef BOARD_H
#define BOARD_H

#include "Arduino.h"
#include "square.h"
#include "enum.h"
#include "event.h"

struct Coord{
    int file;
    int rank;
};

class Board{
public:
    Board();
    Event pollEvent(const Event& prev, Player turn);
    void updateBoard(const Event& event);
    void scanBoard();
    Coord detectChange();

    // print statements
    void printSerial();
    void printLED();

    Square board[9][9]; // indexed by [file][rank]
    bool scannedBoard[9][9];
};



#endif