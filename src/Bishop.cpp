#include "../inc/Bishop.h"

Bishop::Bishop(int colour) : ChessPiece(colour, bishop) {}

Bishop::~Bishop() {}

bool Bishop::check_move(const char* initial_pos,
                       const char* final_pos)
{   
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    if (abs(column_1-column_0) == abs(row_1-row_0)) // Moving diagonally
        {
            return true;
        }
    return false;
}

