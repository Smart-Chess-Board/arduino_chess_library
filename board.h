#ifndef BOARD_H
#define BOARD_H

#include "Arduino.h"
#include "square.h"
#include "enum.h"
#include "event.h"

class Board{
public:
    Board();

    // print statements
    void printSerial();
    void printLED();

    Square board[9][9]; // indexed by [file][rank]
};



#endif