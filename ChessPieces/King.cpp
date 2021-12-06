#include "King.h"

King::King(int colour) : ChessPiece(colour, "King") {}

bool King::check_move(const char* initial_pos,
                       const char* final_pos,
                       bool const is_attacking)
{
    int* initial_pos_int = convert_position_to_int(initial_pos);
    int column_0 = initial_pos_int[0];
    int row_0 = initial_pos_int[1];

    int* final_pos_int = convert_position_to_int(final_pos);
    int column_1 = final_pos_int[0];
    int row_1 = final_pos_int[1]; 

    if ((abs(row_1-row_0)<=1) && (abs(column_1-column_0)<=1)) // Moving diagonally
        {
            return true;
        }
        return false;
}
