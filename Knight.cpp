#include "Knight.h"

Knight::Knight(int colour) : ChessPiece(colour, knight) {}

bool Knight::check_move(const char* initial_pos,
                        const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

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
    piece_move_error_message(initial_pos,
                             final_pos);
    return false;
} 