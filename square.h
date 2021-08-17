#ifndef SQUARE_H
#define SQUARE_H

#include "enum.h"

class Square{
public:
    Square();
    Square(Piece piece, Player color, bool hasPiece = false);

    bool hasPiece;
    Piece piece;
    Player pieceColor;
};

#endif