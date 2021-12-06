#include "ChessPiece.h"

ChessPiece::ChessPiece(int colour, std::string piece_type) :
         colour(colour), piece_type(piece_type) {}

bool ChessPiece::check_move_in_bounds(const char* final_pos) const
{
    if (final_pos[0] > 'H' || final_pos[0] < 'A' || 
        final_pos[1] > '8' || final_pos[1] <'1')
        {
            return false;
        } 
    return true;
}

