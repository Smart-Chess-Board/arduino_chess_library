#include "utility.h"

// coordinates
bool operator==(const Coord& lhs, const Coord& rhs){
    return (lhs.file == rhs.file && lhs.rank == rhs.rank);
}

char intToFileUpper(uint8_t file){
    return 'A'-1 + file;
}

char intToFileLower(uint8_t file){
    return 'a'-1 + file;
}

String getCoordUpper(uint8_t file, uint8_t rank){
    return intToFileUpper(file) + String(rank);
}

String getCoordLower(uint8_t file, uint8_t rank){
    return intToFileLower(file) + String(rank);
}

uint8_t fileToInt(char file){
    if ('A' <= file && file <= 'H')
        return file-'A'+1;
    else if ('a' <= file && file <= 'h')
        return file-'a'+1;
    else
        return -1;
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

// arduino
String readStringFromSerial(){
    while (Serial.available() == 0);
    return Serial.readString();
}

// states
String stateName(State state){
    switch(state){
        case GREEN:     return "GREEN";
        case MOVE:      return "MOVE";
        case CAPTURE1:  return "CAPTURE1";
        case CAPTURE2:  return "CAPTURE2";
        case KING:      return "KING";
        case CASTLE1:   return "CASTLE1";
        case CASTLE2:   return "CASTLE2";
        case PROMO1:    return "PROMO1";
        case PROMO2:    return "PROMO2";
        case PROMO3:    return "PROMO3";
        case RED:       return "RED";
        case NONE:      return "NONE";
        default:        return "NONE";
    }
}