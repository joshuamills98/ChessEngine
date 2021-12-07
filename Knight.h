#ifndef knight_hpp
#define knight_hpp

#include "ChessPiece.h"

class Knight : public ChessPiece {

    public:
        Knight(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♞" : "♘");}
        ~Knight() {};

};

#endif