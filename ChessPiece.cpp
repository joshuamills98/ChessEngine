#include "ChessPiece.h"

ChessPiece::ChessPiece(int colour, PieceType piece_type) :
         colour(colour), piece_type(piece_type) {}

void ChessPiece::piece_move_error_message(const char* initial_pos,
                                          const char* final_pos)
{
    std::cout << (colour == black ? "Black's " : "White's ")
              << piece_lookup(piece_type)
              << " cannot move to "
              << final_pos << "!" << std::endl;
}

