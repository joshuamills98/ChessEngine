#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "ChessConstants.h"

class ChessPiece {
    // Base class to define a standard chess piece
    
    // DATA MEMBERS
    // int colour - colour of piece (-1 = black, +1 = white) 
    //  the polarity of this data member is used to reduce code throughout the functionality
    // PieceType piece_type - integer describing type of piece

    // FUNCTIONALITY
    // GENERAL FUNCTIONS FOR ALL CHESS PIECES: will be defined by used by all pieces
    // PAWN-SPECIFIC FUNCTIONS: function to manage en passant and double jump for first move
    // ROOK AND KING SPECIFIC FUNCTION: Castling functionality
    // KING SPECIFIC FUNCTIONS: In check functionality

    protected:
        int colour; // -1 = black, 1= white
        PieceType piece_type;

    public:
        ChessPiece(int colour, PieceType piece_type);
        virtual ~ChessPiece();

        // ========= GENERAL FUNCTIONS FOR ALL CHESS PIECES ========

        virtual bool check_move(const char* initial_pos,    // Check the move is valid based on individual pieces logic
                                const char* final_pos) = 0; 
        virtual std::string get_piece_unicode() const = 0;  // Piece unicode is useful for the printing of the board

        // getters
        PieceType get_piece_type() {return piece_type;};
        int get_colour() {return colour;};

        // ========== PAWN-SPECIFIC FUNCTIONS =============== 

        virtual bool get_en_passant_flag() const {return false;}
        virtual void set_move_flag(){} 
        virtual void set_en_passant_flag(bool flag){}
        virtual bool get_move_flag() const {return false;}
        
        // ========== ROOK AND KING SPECIFIC FUNCTIONS =====

        virtual void set_castle_flag(){}
        virtual bool get_castle_flag() const {return false;}

        // ========== KING SPECIFIC FUNCTIONS ========

        virtual void set_check_flag(bool in_check){}
        virtual bool get_check_flag() const {return false;}
};

#endif // !chesspiece_hpp
