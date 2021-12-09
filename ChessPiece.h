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

        virtual bool check_move(const char* initial_pos,
                                const char* final_pos) = 0;

        virtual std::string get_piece_unicode() const = 0;
        
        virtual bool get_en_passant_flag(){return true;}
        virtual void set_move_flag(){}
        virtual void set_en_passant_flag(bool flag){}
        virtual bool get_move_flag(){return true;}
        
        PieceType get_piece_type() {return piece_type;};
        int get_colour() {return colour;};
        // void piece_move_error_message(const char* initial_pos,
                                    //   const char* final_pos);
};

#endif // !chesspiece_hpp
