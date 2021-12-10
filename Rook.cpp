#include "Rook.h"

Rook::Rook(int colour) : ChessPiece(colour, rook), can_castle(true) {}

Rook::~Rook(){}

bool Rook::check_move(const char* initial_pos,
                      const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if ((row_0 == row_1) || // Case 1: Moving horizontally
        (column_0 == column_1)) // Case 2: Moving vertically
        {
            return true;
        }
    // piece_move_error_message(initial_pos,
    //                          final_pos);
    return false;
}

