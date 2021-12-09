#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King : public ChessPiece {

    public:
        King(int colour);
        ~King();

        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♚" : "♔");}

};

#endif 
