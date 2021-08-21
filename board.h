#ifndef BOARD_H
#define BOARD_H

#include "Arduino.h"
#include "square.h"
#include "enum.h"
#include "event.h"
#include "utility.h"

struct Coord{
    uint8_t file;
    uint8_t rank;
};

class Board{
public:
    Board();
    Event pollEvent(State state, const Event& prev, Player turn);
    void update(const Event& event);
    void scanBoard();
    Coord detectChange();

    // print statements
    void printSerial();
    void printLED();

    Square board[9][9]; // indexed by [file][rank]
    bool scannedBoard[9][9];
};



#endif