#include "board.h"

Board::Board(){
    for (int file = 1; file <= 8; file++){
        // set piece colors
        for (int rank = 1; rank <= 2; rank++){
            board[file][rank].piece.color = white;
        }
        for (int rank = 7; rank <= 8; rank++){
            board[file][rank].piece.color = black;
        }
        // set pawns
        board[file][2].piece.type = pawn;
        board[file][7].piece.type = pawn;
    }
    // set pieces
    for (int rank = 1; rank <= 8; rank += 7){
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
    for (int rank = 8; rank >= 1; rank--){
        for (int file = 1; file <= 8; file++){
            char c = board[file][rank].piece.type;
            Serial.print(c);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void Board::printLED(){

}