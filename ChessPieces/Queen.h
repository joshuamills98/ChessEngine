#include "ChessPiece.h"

class Queen : public ChessPiece {

    public:
        Queen(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos,
                        bool const is_attacking) override; 
};