#include "Pawn.h"

Pawn::Pawn(int colour) : ChessPiece(colour, pawn) , has_moved(false), en_passant(false) {}

Pawn::~Pawn(){}

bool Pawn::check_move(const char* initial_pos,
                      const char* final_pos) 
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if (colour*row_0>colour*row_1) // Black pawns can't move up the board, white pawns can't move down the board
    {
        // Case 1: pawn hasn't yet moved
        if (!has_moved)
        {
            if ((abs(row_1-row_0)<=2) && (column_0==column_1)) // If moving 2 or 1 positions ahead
            {
                return true;
            }

            if ((abs(row_1-row_0)==abs(column_1-column_0)) && (row_1==row_0-colour)) // If moving diagonally forward ("colour" ensures correct direction)
            {
                return true;
            }
            return false;
        }
        else // Case 2: pawn has moved already
        {
            if (((abs(row_1-row_0)==1) && (column_0==column_1)) || // 1 position ahead
                ((abs(row_1-row_0)==abs(column_1-column_0)) && (row_1==row_0-colour))) // If moving diagonally forward ("colour" ensures correct direction)
                {
                    return true;
                }
            return false;
        }
    }
    return false;
}    