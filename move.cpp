#include "move.h"

Move::Move(){}

void Move::update(Square** currBoard, Square** prevBoard, Player turn, bool isCastle){
    if (isCastle == true){
        if (turn == white){
            liftFile = E; liftRank = 1;
            if (currBoard[G][1].piece.type == king){
                placeFile = G; placeRank = 1;
                shortCastle = true;
            }
            else{
                placeFile = C; placeRank = 1;
                longCastle = true;
            }
        }
        else if (turn == black){
            liftFile = E; liftRank = 8;
            if (currBoard[G][8].piece.type == king){
                placeFile = G; placeRank = 8;
                shortCastle = true;
            }
            else{
                placeFile = C; placeRank = 8;
                longCastle = true;
            }
        }
    }
    else{ // not castle
        // scan for lift event and place event
        bool foundLift = false;
        bool foundPlace = false;
        for (uint8_t file = 1; file <= 8 && !foundLift && !foundPlace; file++){
            for (uint8_t rank = 1; rank <= 8  && !foundLift && !foundPlace; rank++){
                // check for lift event
                if (prevBoard[file][rank].hasPiece && prevBoard[file][rank].piece.color == turn && !currBoard[file][rank].hasPiece){
                    movedPiece = prevBoard[file][rank].piece.type;
                    liftFile = file;
                    liftRank = rank;
                    foundLift = true;
                }
                // check for place event
                if (currBoard[file][rank].hasPiece && currBoard[file][rank].piece.color == turn){
                    if (!prevBoard[file][rank].hasPiece){
                        placeFile = file;
                        placeRank = rank;
                        foundPlace = true;
                    }
                    else if (prevBoard[file][rank].piece.color != turn){
                        capture = true;
                        placeFile = file;
                        placeRank = rank;
                        foundPlace = true;
                    }
                }
            }
        }
        // error checking
        if (!foundLift || !foundPlace){
            Serial.println("Error while generating moves, could not find the lift and/or place event");
        }

        // check edge cases with pawns
        if (movedPiece == pawn){
            if (currBoard[placeFile][placeRank].piece.type != pawn){ // promotion
                promotion = currBoard[placeFile][placeRank].piece.type;
            }
            if (!capture && liftFile != placeFile){ // en passant
                capture = true;
            }
        }
    }
}

 
void Move::reset(){
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