#include "ChessConstants.h"

std::string piece_lookup(int piece_type)
{
    switch(piece_type) {
        case pawn :
            return "Pawn";
        case bishop :
            return "Bishop";
        case rook :
            return "Rook";
        case knight :
            return "Knight";
        case queen :
            return "Queen";
        case king :
            return "King";
    }
    throw std::runtime_error("No given piece type");
}
