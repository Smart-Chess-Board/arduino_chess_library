#ifndef ENUM_H
#define ENUM_H

enum pieceType{
    pawn    = 'P',
    rook    = 'R',
    knight  = 'N',
    bishop  = 'B',
    queen   = 'Q',
    king    = 'K',
    empty   = '.'
};

enum player{
    white,
    black,
    none // used for empty squares / reset FSM
};

enum files{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8
};

#endif