#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece 
{
    bool can_castle;

    public:
        Rook(int colour);
        ~Rook();

        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♜" : "♖");}

        void set_castle_flag(){this->can_castle=false;}
        bool get_castle_flag() const {return can_castle;}
};

#endif
