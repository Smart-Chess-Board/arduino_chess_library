#ifndef UTILITY_H
#define UTILITY_H

#include "enum.h"
#include "Arduino.h"
#include "piece.h"

// coordinate conversions
char intToFileUpper(int file);
char intToFileLower(int file);
String getCoordUpper(int file, int rank);
String getCoordLower(int file, int rank);
int fileToInt(char file);

// pieces
String pieceName(PieceType type);
String pieceName(const Piece& piece);

// arduino
String readStringFromSerial();

#endif