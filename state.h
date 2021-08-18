#ifndef STATE_H
#define STATE_H

#include "Arduino.h"
#include "event.h"

enum State{
    GREEN,      // start state of move
    MOVE,       // move piece
    CAPTURE1,   // capture piece
    CAPTURE2,
    KING,  // move king
    CASTLE1,    // castle
    CASTLE2,
    PROMO1,     // promotions
    PROMO2,
    PROMO3,
    RED1,        // end state
    RED2,
    NONE,       // empty state used for reset
};

// main state function
State nextState(State state, Event* curr, Event* prev);

// individual state functions
State _nextStateFromGreen(Event* curr, Event* prev);
State _nextStateFromMove(Event* curr, Event* prev);
State _nextStateFromCapture1(Event* curr, Event* prev);
State _nextStateFromCapture2(Event* curr, Event* prev);
State _nextStateFromKing(Event* curr, Event* prev);
State _nextStateFromCastle1(Event* curr, Event* prev);
State _nextStateFromCastle2(Event* curr, Event* prev);
State _nextStateFromPromo1(Event* curr, Event* prev);
State _nextStateFromPromo2(Event* curr, Event* prev);
State _nextStateFromPromo3(Event* curr, Event* prev);
State _nextStateFromRed1(Event* curr, Event* prev);
State _nextStateFromRed2(Event* curr, Event* prev);

// helper functions
bool _noChange(Event* curr);
bool _pieceReplaced(Event* curr, Event* prev);
bool _isPromotion(Event* curr);

#endif