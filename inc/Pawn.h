#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {

    bool has_moved;
    bool en_passant;

    public:
        Pawn(int colour);
        ~Pawn();

        bool check_move(const char* initial_position,
                        const char* final_position) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♟" : "♙");}

        bool get_move_flag() const {return has_moved;}
        void set_move_flag() {has_moved = true;}
        bool get_en_passant_flag() const {return en_passant;}
        void set_en_passant_flag(bool flag) {en_passant = flag;}
};  

#endif 
