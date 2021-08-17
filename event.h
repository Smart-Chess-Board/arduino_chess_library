#ifndef EVENT_H
#define EVENT_H

#include "enum.h"
#include "piece.h"
#include "Arduino.h"

class Event{
public:
    Event(Player player, Action action, PieceType type, Player color, int f, int r);
    void printSerial();

    // members that describe the event
    Player player;
    Action action;
    Piece piece;
    bool isPieceAlly;

    // coordinates of the event
    int file;
    int rank;
};

#endif