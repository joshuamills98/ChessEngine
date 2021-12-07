#ifndef chessboard_hpp
#define chessboard_hpp

#include "ChessPiece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "Knight.h"
#include "ChessConstants.h"

class ChessBoard 
{
    ChessPiece* chessboard[8][8];
    int turn; // Whose turn is it?

    public:
        ChessBoard();
        ~ChessBoard();

        void delete_all_pieces();
        void create_all_pieces();
        void resetBoard();


        // =========== High level move checks ============
        bool check_move_main(const char* initial_pos, const char* final_pos) const;
        bool is_valid_input(const char* initial_pos,  const char* final_pos) const;
        bool check_move_format(const char* initial_pos, const char* final_pos) const;
        bool check_move_targets_piece(const char* initial_pos) const;
        bool check_is_turn(const char* initial_pos) const;
        bool check_move_not_null(const char* initial_pos,  const char* final_pos) const;
        bool check_move_not_crossing(const char* initial_pos,  const char* final_pos) const;
        bool check_not_attacking_own_team(const char* initial_pos,  const char* final_pos) const;

        void submitMove(const char* initial_pos,  const char* final_pos);
        void print_board();

};

#endif