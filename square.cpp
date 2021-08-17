#include "square.h"

Square::Square(){
    hasPiece = false;
    piece.type = empty;
    piece.color = none;
}

Square::Square(PieceType type, Player color){
    piece.type = type;
    piece.color = color;
    hasPiece = (piece.type != empty);

}

Square::Square(const Piece& p){
    piece.type = p.type;
    piece.color = p.color;
    hasPiece = (piece.type != empty);
}


