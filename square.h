#ifndef SQUARE_H
#define SQUARE_H

#include "enum.h"

class Square{
public:
    Square();
    Square(pieceType piece, player color, bool hasPiece = false);

    bool hasPiece;
    pieceType piece;
    player color;
};

#endif