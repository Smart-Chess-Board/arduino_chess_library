#include "piece.h"

Piece::Piece(){
    type = empty;
    color = none;
}

Piece::Piece(PieceType type, Player color){
    type = type;
    color = color;
}

Piece::Piece(Player color, PieceType type){
    color = color;
    type = type;
}