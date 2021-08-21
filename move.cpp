#include "move.h"

Move::Move(){}

void Move::updateMove(Square** currBoard, Square** prevBoard){
    
}


void Move::resetMove(){
    // move info
    movedPiece = empty;
    capture = false;
    liftFile = 0;
    liftRank = 0;
    placeFile = 0;
    placeRank = 0;
    // castle info
    shortCastle = false;
    longCastle = false;
    // promotion info
    promotion = empty;
}

String Move::getLongAlgebraicNotation(){
    // handle castles
    if (shortCastle == true){
        return "0-0";
    }
    else if (longCastle == true){
        return "0-0-0";
    }
    
    char piece = movedPiece;
    String notation = String(piece);
    notation += getCoordLower(liftFile, liftRank);
    if (capture == true) notation += "x";
    else notation += "-";
    notation += getCoordLower(placeFile, placeRank);
    if (promotion != empty){
        piece = promotion;
        notation += "=" + String(piece);
    }

    return notation;
}

String Move::getUCINotation(){
    String notation = getCoordLower(liftFile, liftRank) + getCoordLower(placeFile, placeRank);
    if (promotion != empty){
        char piece = promotion + 32; // lowercase
        notation += String(piece);
    }
    return notation;
}