#ifndef EVENT_H
#define EVENT_H

#include "enum.h"
#include "piece.h"
#include "Arduino.h"

class Event{
public:
    Event();
    Event(PieceType promo, uint8_t f, uint8_t r);
    Event(Player player, Action action, PieceType type, Player color, uint8_t f, uint8_t r);
    void printSerial();

    // members that describe the event
    Player player;
    Action action;
    Piece piece;
    bool isPieceAlly;

    // coordinates of the event
    uint8_t file;
    uint8_t rank;

    // members for fsm
    bool isNullEvent;
    PieceType promotion = empty;
};

#endif