#ifndef MOVE_H
#define MOVE_H

#include "Arduino.h"
#include "enum.h"
#include "utility.h"

class Move {
public:
    Move();
    void update(Square currBoard[9][9], Square prevBoard[9][9], Player turn, bool isCastle);
    void reset();
    String getLongAlgebraicNotation();
    String getUCINotation();

    // move info
    PieceType movedPiece = empty;
    bool capture = false;
    uint8_t liftFile = 0;
    uint8_t liftRank = 0;
    uint8_t placeFile = 0;
    uint8_t placeRank = 0;
    // castle info
    bool shortCastle = false;
    bool longCastle = false;
    // promotion info
    PieceType promotion = empty;
};

#endif