#include "Knight.h"

Knight::Knight(int colour) : ChessPiece(colour, "Knight") {}

bool Knight::check_move(const char* initial_pos,
                        const char* final_pos,
                        bool const is_attacking)
{
    int* initial_pos_int = convert_position_to_int(initial_pos);
    int column_0 = initial_pos_int[0];
    int row_0 = initial_pos_int[1];

    int* final_pos_int = convert_position_to_int(final_pos);
    int column_1 = final_pos_int[0];
    int row_1 = final_pos_int[1]; 

    if ((row_1 == row_0+2 && column_1 == column_0+1) ||
        (row_1 == row_0-2 && column_1 == column_0+1) ||
        (row_1 == row_0+2 && column_1 == column_0-1) ||
        (row_1 == row_0-2 && column_1 == column_0-1) ||
        (row_1 == row_0+1 && column_1 == column_0+2) ||
        (row_1 == row_0-1 && column_1 == column_0+2) ||
        (row_1 == row_0+1 && column_1 == column_0-2) ||
        (row_1 == row_0-1 && column_1 == column_0-2))
    {
        return true;
    }
    return false;
} 