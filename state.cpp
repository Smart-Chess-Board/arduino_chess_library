#include "state.h"

// main state function
State nextState(State state, const Event& curr, const Event& prev){
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
        case RED:       return _nextStateFromRed(curr, prev);
        case NONE:      return NONE;
        default:        return NONE;
    }
}

// called at end of arduino loop to update prev event
void updatePrevEvent(const Event& curr, Event& prev, State state, bool stateChange){
    if (curr.isNullEvent == true || stateChange == false){
        return;
    }
    if (state == CAPTURE2 && curr.action == lift && curr.isPieceAlly == false){
        return;
    }

    prev = curr; // update event;
}

// helper state function
State _nextStateFromGreen(const Event& curr, const Event& prev){
    if (_noChange(curr)) return GREEN;
    else if (curr.action == lift && curr.isPieceAlly == false) return CAPTURE1;
    else if (curr.action == lift && curr.isPieceAlly == true && curr.piece.type == king) return KING;
    else if (curr.action == lift && curr.isPieceAlly == true) return MOVE;
    else return GREEN;
}

State _nextStateFromMove(const Event& curr, const Event& prev){
    if (_noChange(curr)) return MOVE;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (curr.action == lift && curr.isPieceAlly == false) return CAPTURE2;  // TODO: edge case with prev evet here
    else if (_isPromotion(curr)) return PROMO1;
    else if (curr.action == place && curr.isPieceAlly == true) return RED;
    else return MOVE;
}

State _nextStateFromCapture1(const Event& curr, const Event& prev){
    if (_noChange(curr)) return CAPTURE1;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (curr.action == lift && curr.isPieceAlly == true) return CAPTURE2;
    else return CAPTURE1;
}

State _nextStateFromCapture2(const Event& curr, const Event& prev){
    if (_noChange(curr)) return CAPTURE2;
    else if (_pieceReplaced(curr, prev)) return CAPTURE1;
    else if (_isPromotion(curr)) return PROMO1;
    else if (curr.action == place && curr.isPieceAlly == true) return RED;
    else return CAPTURE2;
}

State _nextStateFromKing(const Event& curr, const Event& prev){
    if (_noChange(curr)) return KING;
    else if (_pieceReplaced(curr, prev)) return GREEN;
    else if (curr.action == lift && curr.isPieceAlly == false) return CAPTURE2;
    else if (curr.action == place && curr.isPieceAlly == true && curr.piece.type == king){
        if (abs(curr.file - prev.file) == 2) return CASTLE1;
        else return RED;
    }
    else return KING;
}

State _nextStateFromCastle1(const Event& curr, const Event& prev){
    if (_noChange(curr)) return CASTLE1;
    else if (curr.action == lift && curr.isPieceAlly == true && curr.piece.type == rook) return CASTLE2;
    else return CASTLE1;
}

State _nextStateFromCastle2(const Event& curr, const Event& prev){
    if (_noChange(curr)) return CASTLE2;
    else if (_pieceReplaced(curr, prev)) return CASTLE1;
    else if (curr.action == place && curr.isPieceAlly == true && curr.piece.type == rook) return RED;
    else return CASTLE2;
}

State _nextStateFromPromo1(const Event& curr, const Event& prev){
    // select promotion type
    PieceType promo = curr.promotion;
    if (promo == queen || promo == rook || promo == bishop || promo == knight) return PROMO2;
    else return PROMO1;
}

State _nextStateFromPromo2(const Event& curr, const Event& prev){
    if (_noChange(curr)) return PROMO2;
    else if (curr.action == lift && curr.isPieceAlly == true 
            && curr.piece.type == pawn && curr.file == prev.file && curr.rank == prev.rank) return PROMO3;
    else return PROMO2;
}
State _nextStateFromPromo3(const Event& curr, const Event& prev){
    if (_noChange(curr)) return PROMO3;
    else if (curr.action == place && curr.file == prev.file && curr.rank == prev.rank) return RED;
    else return PROMO3;
}

State _nextStateFromRed(const Event& curr, const Event& prev){
    return RED;
}

// helper functions
bool _noChange(const Event& curr){
    return curr.isNullEvent;
}

bool _pieceReplaced(const Event& curr, const Event& prev){
    if (curr.file != prev.file) return false;
    else if (curr.rank != prev.rank) return false;
    else if (curr.piece != prev.piece) return false;
    else if (curr.action == place && prev.action == lift) return true;
    else return false;
}

bool _isPromotion(const Event& curr){
    if (curr.action == place && curr.isPieceAlly == true && curr.piece.type == pawn){
        uint8_t promotionRank;
        if (curr.player == white) promotionRank = 8;
        else promotionRank = 1;
        
        if (curr.rank == promotionRank) return true;
        else return false;
    }
    else{
        return false;
    }
}