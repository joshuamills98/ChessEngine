#ifndef bishop_hpp
#define bishop_hpp


# include "ChessPiece.h"

class Bishop : public ChessPiece {

    public:
        Bishop(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos,
                        bool const is_attacking) override; 
};

#endif // !1
