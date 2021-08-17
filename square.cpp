#include "square.h"

Square::Square(){
    hasPiece = false;
    piece = empty;
    pieceColor = none;
}

Square::Square(Piece piece, Player color, bool hasPiece = false){
    piece = piece;
    pieceColor = color;
    hasPiece = hasPiece;
}

