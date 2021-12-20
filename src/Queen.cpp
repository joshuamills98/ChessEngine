#include "../inc/Queen.h"

Queen::Queen(int colour) : ChessPiece(colour, queen) {}

Queen::~Queen() {}

bool Queen::check_move(const char* initial_pos,
                       const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if ((row_0 == row_1) || // Case 1: Moving horizontally
        (column_0 == column_1) || // Case 2: Moving vertically
        (abs(column_1-column_0) == abs(row_1-row_0))) // Case 3: Moving diagonally
        {
            return true;
        }
        return false;
}

