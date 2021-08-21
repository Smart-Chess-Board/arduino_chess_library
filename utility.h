#ifndef UTILITY_H
#define UTILITY_H

#include "enum.h"
#include "Arduino.h"
#include "piece.h"
#include "state.h"
#include "square.h"

// coordinates
struct Coord{
    uint8_t file;
    uint8_t rank;
};

bool operator==(const Coord& lhs, const Coord& rhs);

char intToFileUpper(uint8_t file);
char intToFileLower(uint8_t file);
String getCoordUpper(uint8_t file, uint8_t rank);
String getCoordLower(uint8_t file, uint8_t rank);
uint8_t fileToInt(char file);

// pieces
String pieceName(PieceType type);
String pieceName(const Piece& piece);

// arduino
String readStringFromSerial();

// states
String stateName(State state);

// data movement
void copyBoard(Square src[9][9], Square dst[9][9]);
void printBoard(Square board[9][9]);

#endif