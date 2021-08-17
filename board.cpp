#include "board.h"

Board::Board(){
    for (int file = 1; file <= 8; file++){
        // set piece colors
        for (int rank = 1; rank <= 2; rank++){
            board[file][rank].pieceColor = white;
        }
        for (int rank = 7; rank <= 8; rank++){
            board[file][rank].pieceColor = black;
        }
        // set pawns
        board[file][2].piece = pawn;
        board[file][7].piece = pawn;
    }
    // set pieces
    for (int rank = 1; rank <= 8; rank += 7){
        board[A][rank].piece = rook;
        board[B][rank].piece = knight;
        board[C][rank].piece = bishop;
        board[D][rank].piece = queen;
        board[E][rank].piece = king;
        board[F][rank].piece = bishop;
        board[G][rank].piece = knight;
        board[H][rank].piece = rook;
    }
}

void Board::printSerial(){
    for (int rank = 8; rank >= 1; rank--){
        for (int file = 1; file <= 8; file++){
            char c = board[file][rank].piece;
            Serial.print(c);
            Serial.print(" ");
        }
        Serial.println();
    }
}

void Board::printLED(){

}