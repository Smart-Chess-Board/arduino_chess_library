#ifndef PIECE_H
#define PIECE_H

#include "enum.h"

class Piece{
public:
    Piece();
    Piece(PieceType type, Player color);
    Piece(Player color, PieceType type);
    bool operator==(const Piece& piece);
    bool operator!=(const Piece& piece);

    PieceType type;
    Player color;
};

#endif