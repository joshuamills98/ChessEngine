#include "Pawn.h"

Pawn::Pawn(int colour) : ChessPiece(colour, "Pawn") , has_moved(false) {}

bool Pawn::check_move(const char* initial_pos,
                      const char* final_pos,
                      bool const is_attacking) 
{
    int* initial_pos_int = convert_position_to_int(initial_pos);
    int column_0 = initial_pos_int[0];
    int row_0 = initial_pos_int[1];

    int* final_pos_int = convert_position_to_int(final_pos);
    int column_1 = final_pos_int[0];
    int row_1 = final_pos_int[1]; 

    if (row_1 < row_0)
    {
        return false; // Pawn can't move backward along column
    }

    if (!is_attacking) // If pawn is not attacking
    {
        if (column_0 != column_1) // Can only move along column
        {
            return false;
        }

        if (!this->has_moved) // If pawn hasn't yet moved
        {
            // Can not move more than 2 posiitons away from start
            if (this->colour*row_1>this->colour*row_0+2) 
            {
                return false;
            }
            set_move_flag();
            return true;
        }
        else // If pawn has already moved 
        { // Can not move more than one position from start
            if (this->colour*row_1>this->colour*row_0+1)
            {
                return false;
            }
            return true;
        }
    } else // If pawn is attacking another piece
    {
        if (row_1==row_0+this->colour) // Pawn can only move one place forward diagonally
        {
            if (column_1==column_0+1 || column_1==column_0-1) // 
            {
                return true;
            }
        }
        return false;
    }
} 