#ifndef chessboard_hpp
#define chessboard_hpp

#include "string.h"
#include "./ChessPieces/ChessPiece.h"
#include "./ChessPieces/Rook.h"
#include "./ChessPieces/Bishop.h"
#include "./ChessPieces/Queen.h"
#include "./ChessPieces/King.h"
#include "./ChessPieces/Pawn.h"
#include "./ChessPieces/Knight.h"

#include "ChessConstants.h"

class ChessBoard 
{
    ChessPiece* chessboard[8][8];

    public:
        ChessBoard();
        void submitMove(std::string const& pos1, std::string const& pos2);
        void print_board();
        void resetBoard();

};

#endif