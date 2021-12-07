#ifndef rook_hpp
#define rook_hpp

#include "ChessPiece.h"

class Rook : public ChessPiece 
{
    public:
        Rook(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♜" : "♖");}
        ~Rook() {};

};

#endif
