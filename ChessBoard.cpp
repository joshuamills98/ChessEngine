#include "ChessBoard.h"

using namespace chess_constants;

ChessBoard::ChessBoard() 
{
    // Initiate first two rows for white and black
    for (int colour = BLACK; colour <= WHITE; colour += WHITE-BLACK)
    {
        chessboard[colour == BLACK ? 7 : 0][0] = new Rook(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][1] = new Knight(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][2] = new Bishop(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][3] = new Queen(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][4] = new King(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][5] = new Bishop(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][6] = new Knight(colour == BLACK ? BLACK : WHITE);
        chessboard[colour == BLACK ? 7 : 0][7] = new Rook(colour == BLACK ? BLACK : WHITE);
        // Initiate pawns
        
        for (int column = 'A'; column <= 'H'; column++)
        {
            chessboard[colour == BLACK ? 6 : 1][column - 'A'] = new Pawn(colour == BLACK ? BLACK : WHITE);
        } 
    }
}