#include "state.h"

// main state function
State nextState(State state, Event* curr, Event* prev){
    switch(state){
        case GREEN:     return _nextStateFromGreen(curr, prev);
        case MOVE:      return _nextStateFromMove(curr, prev);
        case CAPTURE1:  return _nextStateFromCapture1(curr, prev);
        case CAPTURE2:  return _nextStateFromCapture2(curr, prev);
        case KING:      return _nextStateFromKing(curr, prev);
        case CASTLE1:   return _nextStateFromCastle1(curr, prev);
        case CASTLE2:   return _nextStateFromCastle2(curr, prev);
        case PROMO1:    return _nextStateFromPromo1(curr, prev);
        case PROMO2:    return _nextStateFromPromo2(curr, prev);
        case PROMO3:    return _nextStateFromPromo3(curr, prev);
        case RED1:      return _nextStateFromRed1(curr, prev);
        case RED2:      return _nextStateFromRed2(curr, prev);
        case NONE:      return NONE;
        default:        return NONE;
    }
}

// helper state function
State _nextStateFromGreen(Event* curr, Event* prev){
    if (_noChange(curr)) return GREEN;
    else if (curr->action == lift && curr->isPieceAlly == false) return CAPTURE1;
    else if (curr->action == lift && curr->isPieceAlly == true && curr->piece.type == king) return KING;
    else if (curr->action == lift && curr->isPieceAlly == true) return MOVE;
    else return GREEN;
}

State _nextStateFromMove(Event* curr, Event* prev){
    if (_noChange(curr)) return MOVE;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (_isPromotion(curr)) return PROMO1;
    else if (curr->action == place && curr->isPieceAlly == true) return RED1;
    else return MOVE;
}

State _nextStateFromCapture1(Event* curr, Event* prev){
    if (_noChange(curr)) return CAPTURE1;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (curr->action == lift && curr->isPieceAlly == true) return CAPTURE2;
    else return CAPTURE1;
}

State _nextStateFromCapture2(Event* curr, Event* prev){
    if (_noChange(curr)) return CAPTURE2;
    else if (_pieceReplaced(curr, prev)) return CAPTURE1;
    else if (_isPromotion(curr)) return PROMO1;
    else if (curr->action == place && curr->isPieceAlly == true) return RED1;
    else return CAPTURE2;
}

State _nextStateFromKing(Event* curr, Event* prev){
    if (_noChange(curr)) return KING;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (curr->action == place && curr->isPieceAlly == true && curr->piece.type == king){
        if (abs(curr->file - prev->file) == 2) return CASTLE1;
        else return RED1;
    }
    else return KING;
}

State _nextStateFromCastle1(Event* curr, Event* prev){
    if (_noChange(curr)) return CASTLE1;
    else if (curr->action == lift && curr->isPieceAlly == true && curr->piece.type == rook) return CASTLE2;
    else return CASTLE1;
}

State _nextStateFromCastle2(Event* curr, Event* prev){
    if (_noChange(curr)) return CASTLE2;
    else if (_pieceReplaced(curr, prev)) return CASTLE1;
    else if (curr->action == place && curr->isPieceAlly == true && curr->piece.type == rook) return RED1;
    else return CASTLE2;
}

State _nextStateFromPromo1(Event* curr, Event* prev){
    // select promotion type
    PieceType promo = curr->promotion;
    if (promo == queen || promo == rook || promo == bishop || promo == knight) return PROMO2;
    else return PROMO1;
}

State _nextStateFromPromo2(Event* curr, Event* prev){
    if (_noChange(curr)) return PROMO2;
    else if (curr->action == lift && curr->isPieceAlly == true 
            && curr->piece.type == pawn && curr->file == prev->file && curr->rank == prev->rank) return PROMO3;
    else return PROMO2;
}
State _nextStateFromPromo3(Event* curr, Event* prev){
    if (_noChange(curr)) return PROMO3;
    else if (curr->action == place && curr->file == prev->file && curr->rank == prev->rank) return RED1;
    else return PROMO3;
}

State _nextStateFromRed1(Event* curr, Event* prev){
    if (_noChange(curr)) return RED1;
    else if (curr->player != prev->player) return RED2;
    else return RED1;
}

State _nextStateFromRed2(Event* curr, Event* prev){
    if (_noChange(curr)) return RED2;
    else if (curr->player != prev->player) return GREEN;
    else return RED2;
}

// helper functions
bool _noChange(Event* curr){
    return curr->isNullEvent;
}

bool _pieceReplaced(Event* curr, Event* prev){
    if (curr->file != prev->file) return false;
    else if (curr->rank != prev->rank) return false;
    else if (curr->piece != prev->piece) return false;
    else if (curr->action == place && prev->action == lift) return true;
    else return false;
}

bool _isPromotion(Event* curr){
    if (curr->action == place && curr->isPieceAlly == true && curr->piece.type == pawn){
        int promotionRank;
        if (curr->player == white) promotionRank = 8;
        else promotionRank = 1;
        
        if (curr->rank == promotionRank) return true;
        else return false;
    }
    else{
        return false;
    }
}