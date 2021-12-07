#ifndef chesspiece_hpp
#define chesspiece_hpp

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "helper.h"
#include "ChessConstants.h"

class ChessPiece {
    // Class to define a standard chess piece
    protected:
        int colour; // -1 = black, 1= white
        PieceType piece_type;

    public:
        ChessPiece(int colour, PieceType piece_type);
        virtual ~ChessPiece(){};

        virtual bool check_move(const char* initial_pos,
                                const char* final_pos) = 0;

        virtual std::string get_piece_unicode() const = 0;
        
        PieceType get_piece_type() {return piece_type;};
        int get_colour() {return colour;};
        void piece_move_error_message(const char* initial_pos,
                                      const char* final_pos);
};

#endif // !chesspiece_hpp
