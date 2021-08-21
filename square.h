#ifndef SQUARE_H
#define SQUARE_H

#include "enum.h"
#include "piece.h"

class Square{
public:
    Square();
    Square(PieceType type, Player color);
    Square(const Piece& p);
    bool hasPiece();

    Piece piece;
};

#endif