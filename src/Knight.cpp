#include "../inc/Knight.h"

Knight::Knight(int colour) : ChessPiece(colour, knight) {}

Knight::~Knight() {}

bool Knight::check_move(const char* initial_pos,
                        const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    // There are 8 possible moves a knight can make given by the vectors (+/-2, +/-1) or (+/-1, +/-2)
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