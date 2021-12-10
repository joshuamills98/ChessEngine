#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "ChessConstants.h"

class ChessPiece {
    // Class to define a standard chess piece
    protected:
        int colour; // -1 = black, 1= white
        PieceType piece_type;

    public:
        ChessPiece(int colour, PieceType piece_type);
        virtual ~ChessPiece();

        // General functions for chess pieces
        virtual bool check_move(const char* initial_pos,
                                const char* final_pos) = 0;
        virtual std::string get_piece_unicode() const = 0;
        
        // Pawnspecific functions 
        virtual bool get_en_passant_flag() const {return false;}
        virtual void set_move_flag(){}
        virtual void set_en_passant_flag(bool flag){}
        virtual bool get_move_flag() const {return false;}
        
        // Rook and king-specific functions
        virtual void set_castle_flag(){}
        virtual bool get_castle_flag() const {return false;}

        // King-specific functions
        virtual void set_check_flag(bool in_check){}
        virtual bool get_check_flag() const {return false;}


        PieceType get_piece_type() {return piece_type;};
        int get_colour() {return colour;};

};

#endif // !chesspiece_hpp
