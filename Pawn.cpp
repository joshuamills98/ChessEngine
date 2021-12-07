#include "Pawn.h"

Pawn::Pawn(int colour) : ChessPiece(colour, pawn) , has_moved(false) {}

bool Pawn::check_move(const char* initial_pos,
                      const char* final_pos) 
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if (colour*row_0>colour*row_1) // Black pawns can't move up thew board, white pawns cant move down
    {
        // Case 1: pawn hasn't yet moved
        if (!has_moved)
        {
            if (((abs(row_1-row_0)<=2) && (column_0==column_1)) || // Two positions or 1 ahead
                ((abs(row_1-row_0)==abs(column_1-column_0)) && (row_1==row_0-colour))) // Taking diagonally forward
                {
                    return true;
                }
            piece_move_error_message(initial_pos,
                                     final_pos);
            return false;
        }
        else // Case 2: pawn has moved already
        {
            if (((abs(row_1-row_0)==1) && (column_0==column_1)) || // Two positions or 1 ahead
                ((abs(row_1-row_0)==abs(column_1-column_0)) && (row_1==row_0-colour))) // Taking diagonally forward
                {
                    return true;
                }
                
            piece_move_error_message(initial_pos,
                                     final_pos);
            return false;
        }
    }
    piece_move_error_message(initial_pos,
                             final_pos);
    return false;
}    