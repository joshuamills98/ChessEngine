#ifndef knight_hpp
#define knight_hpp

#include "ChessPiece.h"

class Knight : public ChessPiece {

    public:
        Knight(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos,
                        bool const is_attacking) override; 
};

#endif