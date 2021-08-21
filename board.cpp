#include "board.h"

#define SW_TESTING

Board::Board(){
    for (uint8_t file = 1; file <= 8; file++){
        // set piece colors
        for (uint8_t rank = 1; rank <= 2; rank++){
            board[file][rank].piece.color = white;
        }
        for (uint8_t rank = 7; rank <= 8; rank++){
            board[file][rank].piece.color = black;
        }
        // set pawns
        board[file][2].piece.type = pawn;
        board[file][7].piece.type = pawn;
    }
    // set pieces
    for (uint8_t rank = 1; rank <= 8; rank += 7){
        board[A][rank].piece.type = rook;
        board[B][rank].piece.type = knight;
        board[C][rank].piece.type = bishop;
        board[D][rank].piece.type = queen;
        board[E][rank].piece.type = king;
        board[F][rank].piece.type = bishop;
        board[G][rank].piece.type = knight;
        board[H][rank].piece.type = rook;
    }
}

void Board::printSerial(){
    for (uint8_t rank = 8; rank >= 1; rank--){
        Serial.print(rank);
        Serial.print(" | ");
        for (uint8_t file = 1; file <= 8; file++){
            char c = board[file][rank].piece.type;
            if (board[file][rank].piece.color == black){
                c += 32;
                Serial.print(c);
            }
            else{
                Serial.print(c);
            }
            Serial.print(" ");
        }
        Serial.println();
    }

    Serial.print("    ");
    for (char file = 'A'; file <= 'H'; file++){
        Serial.print("--");
    }
    Serial.print("\n    ");
    for (char file = 'A'; file <= 'H'; file++){
        Serial.print(file);
        Serial.print(" ");
    }
    Serial.println();
}

void Board::printLED(){

}

/*
Note that the pollEvent function will not be called if the current state is PROMO1 or PROMO3
In PROMO1, need to wait for arduino to read a promotion type from the user
In PROMO3, need to generate the state differently, since the piece being placed
differs from the original piece that was lifted.
*/

Event Board::pollEvent(State state, const Event& prev, Player turn){
#ifdef SW_TESTING
    // format action, coord
    // null event is just null
    // ex. PD6
    String input = readStringFromSerial();
    if (input == "null"){
        Event nullEvent;
        return nullEvent;
    }
    if (state == PROMO1){
        if (input == "queen"){
        Event ret(queen, prev.file, prev.rank);
        return ret;
        }
        else if (input == "rook"){
            Event ret(rook, prev.file, prev.rank);
            return ret;
        }
        else if (input == "knight"){
            Event ret(knight, prev.file, prev.rank);
            return ret;
        }
        else if (input == "bishop"){
            Event ret(bishop, prev.file, prev.rank);
            return ret;
        }
        else {
            Event ret;
            return ret;
        }
    }
    else{
        Action action;
        PieceType pieceType;
        Player pieceColor;
        uint8_t file, rank;

        // parse input
        file = fileToInt(input[1]);
        String r = String(input[2]);
        rank = r.toInt();
        if (input[0] == 'L' || input[0] == 'l'){
            action = lift;
            pieceType = board[file][rank].piece.type;
            pieceColor = board[file][rank].piece.color;
        }
        else if (input[0] == 'P' || input[0] == 'p'){
            action = place;
            pieceType = prev.piece.type;
            pieceColor = prev.piece.color;
        }

        Event ret(turn, action, pieceType, pieceColor, file, rank);
        return ret;
    }

#else // FIXME: need to incorporate state into to generate promo events
    if (state == PROMO1){
        // check for select switches
    }
    else{
        Coord change = detectChange();
        if (change.file == -1 and change.rank == -1){
            Event nullEvent;
            return nullEvent;
        }

        Action action;
        PieceType pieceType;
        Player pieceColor;
        uint8_t file = change.file;
        uint8_t rank = change.rank;

        if (scannedBoard[file][rank] == true){ // place event
            action = place;
            pieceType = prev.piece.type;
            pieceColor = prev.piece.color;
        }
        else{ // lift event
            action = lift;
            pieceType = board[file][rank].piece.type;
            pieceColor = board[file][rank].piece.color;
        }
        
        Event ret(turn, action, pieceType, pieceColor, file, rank);
        return ret;
    }
#endif
}

void Board::update(const Event& event){
    if (event.isNullEvent == true || event.action == noAction)
        return;

    uint8_t file = event.file;
    uint8_t rank = event.rank;
    if (event.action == lift){
        board[file][rank].piece.type = empty;
        board[file][rank].piece.color = none;
    }
    else if (event.action == place){
        board[file][rank].piece = event.piece;
    }
}

void Board::scanBoard(){ // implement once hardware is ready

}

Coord Board::detectChange(){
    for (uint8_t file = 1; file <= 8; file++){
        for (uint8_t rank = 1; rank <=8; rank++){
            if (scannedBoard[file][rank] == true && board[file][rank].hasPiece() == false) // piece placed
                return {file, rank};
            else if (scannedBoard[file][rank] == false && board[file][rank].hasPiece() == true) // piece removed
                return {file, rank};
        }
    }
    // no changes
    return {-1, -1}; // invalid Coord to indicate no change
}