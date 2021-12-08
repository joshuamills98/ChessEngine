#ifndef queen_hpp
#define queen_hpp

#include "ChessPiece.h"

class Queen : public ChessPiece {

    public:
        Queen(int colour);
        ~Queen() {};

        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♛" : "♕");}

};

#endif