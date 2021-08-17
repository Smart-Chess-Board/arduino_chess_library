#include "event.h"
#include "utility.h"

Event::Event(Player player, Action action, PieceType type, Player color, int f, int r)
    : player(player), action(action), file(f), rank(r) {
        
    piece.type = type;
    piece.color = color;

    isPieceAlly = (player == piece.color);
}

void Event::printSerial(){
    if (player == white)    Serial.print("White's move: ");
    else                    Serial.print("Black's move: ");

    if (action == lift)     Serial.print("lift ");
    else                    Serial.print("place ");

    if (isPieceAlly)        Serial.print("ally ");
    else                    Serial.println("enemy ");

    Serial.print(pieceName(piece.type));
    Serial.print(" ");

    if (action == lift)     Serial.print("from ");
    else                    Serial.print("on ");

    Serial.println(getCoordUpper(file, rank));

}