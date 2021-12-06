#ifndef pawn_hpp
#define pawn_hpp

#include "ChessPiece.h"

class Pawn : public ChessPiece {

    bool has_moved;

    public:
        Pawn(int colour);
        bool check_move(const char* initial_position,
                        const char* final_position,
                        bool const is_attacking) override; 
        void set_move_flag(){this->has_moved = true;}
};

#endif 
