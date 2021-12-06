#include "Rook.h"

Rook::Rook(int colour) : ChessPiece(colour, "Rook") {}

bool Rook::check_move(const char* initial_pos,
                const char* final_pos,
                bool const is_attacking)
{
    int* initial_pos_int = convert_position_to_int(initial_pos);
    int column_0 = initial_pos_int[0];
    int row_0 = initial_pos_int[1];

    int* final_pos_int = convert_position_to_int(final_pos);
    int column_1 = final_pos_int[0];
    int row_1 = final_pos_int[1]; 

    if ((row_0 == row_1) || // Case 1: Moving horizontally
        (column_0 == column_1)) // Case 2: Moving vertically
        {
            return true;
        }
        return false;
}

