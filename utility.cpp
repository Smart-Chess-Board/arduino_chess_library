#include "utility.h"

// coordinate conversions
char intToFileUpper(int file){
    return 'A'-1 + file;
}

char intToFileLower(int file){
    return 'a'-1 + file;
}

String getCoordUpper(int file, int rank){
    return intToFileUpper(file) + String(rank);
}

String getCoordLower(int file, int rank){
    return intToFileLower(file) + String(rank);
}

// pieces
String pieceName(PieceType type){
    if (type == pawn) return "pawn";
    else if (type == rook) return "rook";
    else if (type == knight) return "knight";
    else if (type == bishop) return "bishop";
    else if (type == queen) return "queen"; 
    else if (type == king) return "king";
    else return "<none>";
}

String pieceName(const Piece& piece){
    if (piece.color == white)
        return "white " + pieceName(piece.type);
    else if (piece.color == black)
        return "black " + pieceName(piece.type);
    else
        return "no piece";
}