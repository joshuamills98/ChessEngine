#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class King : public ChessPiece {
    bool can_castle;
    bool in_check;

    public:
        King(int colour);
        ~King();

        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♚" : "♔");}

        void set_castle_flag() {this->can_castle=false;}
        bool get_castle_flag() const {return !in_check&&can_castle;}

        void set_check_flag(bool in_check) {this->in_check = in_check;}
        bool get_check_flag() const {return false;}

};

#endif 
