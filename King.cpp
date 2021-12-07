#include "King.h"

King::King(int colour) : ChessPiece(colour, king) {}

bool King::check_move(const char* initial_pos,
                       const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if ((abs(row_1-row_0)<=1) && (abs(column_1-column_0)<=1)) // Moving diagonally
        {
            return true;
        }
    piece_move_error_message(initial_pos,
                             final_pos);
    return false;
}
