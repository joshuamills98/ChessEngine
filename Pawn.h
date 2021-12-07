#ifndef pawn_hpp
#define pawn_hpp

#include "ChessPiece.h"

class Pawn : public ChessPiece {

    bool has_moved;

    public:
        Pawn(int colour);
        bool check_move(const char* initial_position,
                        const char* final_position) override; 
        void set_move_flag(){this->has_moved = true;}
        std::string get_piece_unicode() const override {return (colour == black ? "♟︎" : "♙");}
        ~Pawn() {};
};  

#endif 
