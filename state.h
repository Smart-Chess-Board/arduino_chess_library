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
    RED,        // end state
    NONE,       // empty state used for reset
};

// main state function
State nextState(State state, const Event& curr, const Event& prev);
void updatePrevEvent(const Event& curr, Event& prev, State state, bool stateChange); // called at end of arduino loop to update prev event

// individual state functions
State _nextStateFromGreen(const Event& curr, const Event& prev);
State _nextStateFromMove(const Event& curr, const Event& prev);
State _nextStateFromCapture1(const Event& curr, const Event& prev);
State _nextStateFromCapture2(const Event& curr, const Event& prev);
State _nextStateFromKing(const Event& curr, const Event& prev);
State _nextStateFromCastle1(const Event& curr, const Event& prev);
State _nextStateFromCastle2(const Event& curr, const Event& prev);
State _nextStateFromPromo1(const Event& curr, const Event& prev);
State _nextStateFromPromo2(const Event& curr, const Event& prev);
State _nextStateFromPromo3(const Event& curr, const Event& prev);
State _nextStateFromRed(const Event& curr, const Event& prev);

// helper functions
bool _noChange(const Event& curr);
bool _pieceReplaced(const Event& curr, const Event& prev);
bool _isPromotion(const Event& curr);

#endif