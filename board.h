#ifndef BOARD_H
#define BOARD_H

#include "Arduino.h"
#include "square.h"
#include "enum.h"
#include "event.h"
#include "utility.h"

// define pins
#define WA 0
#define WB 1
#define WC 2
#define WD 3
#define WE 4
#define WF 5
#define WG 6
#define WH 7
#define R1 8
#define R2 9
#define R3 10
#define R4 11
#define R5 12
#define R6 13
#define R7 A1
#define R8 A2

class Board{
public:
    Board();
    Event pollEvent(State state, const Event& prev, Player turn);
    Event getEvent(String input, State state, const Event& prev, Player turn);
    void update(const Event& event);
    void scanBoard();
    Coord detectChange();

    // print statements
    void printSerial();
    void printLED();

    Square board[9][9]; // indexed by [file][rank]
    bool scannedBoard[9][9];
    uint8_t filePins[9]; // test lines
    uint8_t rankPins[9]; // read pins
};



#endif