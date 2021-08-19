#include "event.h"
#include "utility.h"

// constructor for null event
Event::Event()
    : player(none), action(noAction), file(-1), rank(-1), isNullEvent(true), isPieceAlly(false) {

    piece.type = empty;
    piece.color = none;
}

// constructor for promotion
Event::Event(PieceType promo, int f, int r)
: promotion(promo), action(noAction), file(f), rank(r), isPieceAlly(true), isNullEvent(false){}

// constructor for other events
Event::Event(Player player, Action action, PieceType type, Player color, int f, int r)
    : player(player), action(action), file(f), rank(r), isNullEvent(false) {
        
    piece.type = type;
    piece.color = color;

    isPieceAlly = (player == piece.color);
}

void Event::printSerial(){
    if (isNullEvent){
        Serial.println("null event");
    }
    else if (action == noAction){
        Serial.println("promotion event");
    }
    else{
        if (player == white)    Serial.print("White's move: ");
        else                    Serial.print("Black's move: ");

        if (action == lift)     Serial.print("lift ");
        else                    Serial.print("place ");

        if (isPieceAlly)        Serial.print("ally ");
        else                    Serial.print("enemy ");

        Serial.print(pieceName(piece.type));
        Serial.print(" ");

        if (action == lift)     Serial.print("from ");
        else                    Serial.print("on ");

        Serial.println(getCoordUpper(file, rank));
    }
}