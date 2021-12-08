#ifndef pawn_hpp
#define pawn_hpp

#include "ChessPiece.h"

class Pawn : public ChessPiece {

    bool has_moved;
    bool en_passant;

    public:
        Pawn(int colour);
        ~Pawn() {};

        bool check_move(const char* initial_position,
                        const char* final_position) override; 
        bool get_move_flag() override {return has_moved;}
        void set_move_flag() override {has_moved = true;}
        bool get_en_passant_flag() override {return en_passant;}
        void set_en_passant_flag(bool flag) override{en_passant = flag;}
        std::string get_piece_unicode() const override {return (colour == black ? "♟︎" : "♙");}
};  

#endif 
