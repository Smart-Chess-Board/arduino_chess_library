#include "square.h"

Square::Square(){
    piece.type = empty;
    piece.color = none;
}

Square::Square(PieceType type, Player color){
    piece.type = type;
    piece.color = color;

}

Square::Square(const Piece& p){
    piece.type = p.type;
    piece.color = p.color;
}

bool Square::hasPiece(){
    return piece.type != empty;
}

