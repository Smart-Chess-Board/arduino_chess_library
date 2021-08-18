#ifndef ENUM_H
#define ENUM_H

enum PieceType{
    pawn    = 'P',
    rook    = 'R',
    knight  = 'N',
    bishop  = 'B',
    queen   = 'Q',
    king    = 'K',
    empty   = '.'
};

enum Player{
    white,
    black,
    none // used for empty squares / reset FSM
};

enum File{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8
};

enum Action{lift, place, noAction};

#endif