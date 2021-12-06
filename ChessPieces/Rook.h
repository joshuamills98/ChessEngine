#include "ChessPiece.h"

class Rook : public ChessPiece 
{
    public:
        Rook(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos,
                        bool const is_attacking) override; 
};