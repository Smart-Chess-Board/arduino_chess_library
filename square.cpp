#include "square.h"

Square::Square(){
    hasPiece = false;
    piece = empty;
    color = none;
}

Square::Square(pieceType piece, player color, bool hasPiece = false){
    piece = piece;
    color = color;
    hasPiece = hasPiece;
}

