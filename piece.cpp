#include "piece.h"

Piece::Piece()
: type(empty), color(none) {}

Piece::Piece(PieceType type, Player color)
: type(type), color(color) {}

Piece::Piece(Player color, PieceType type)
: type(type), color(color) {}

bool Piece::operator==(const Piece& piece){
    return (type == piece.type && color == piece.color);
}

bool Piece::operator!=(const Piece& piece){
    return (type != piece.type || color != piece.color);
}