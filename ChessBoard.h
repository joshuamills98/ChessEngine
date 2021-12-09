#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessConstants.h"
#include "ChessPiece.h"

class ChessBoard 
{
    ChessPiece* chessboard[8][8];
    int turn; // Whose turn is it?
    bool game_over;

    public:
        ChessBoard();
        ~ChessBoard();
        ChessBoard(ChessBoard const& other_chessboard); // Copy Constructor
        ChessBoard &operator=(ChessBoard const& other); // Overloaded Assignment Operator

        // ======= Delete, create and reset ======
        void delete_all_pieces();
        void create_all_pieces();
        void resetBoard();


        // =========== Priority 1 Checks ============
        bool p1_checks(const char* initial_pos, const char* final_pos) const; // 
        bool check_move_format(const char* initial_pos, const char* final_pos) const; // Check move formatted correctly
        bool check_is_turn(const char* initial_pos) const; // Check it is the turn of submission
        bool check_move_targets_piece(const char* initial_pos) const; // Check there is actually a piece at given position
        bool check_game_over() const;

        // =========== Priority 2 Checks ============
        bool p2_checks(const char* initial_pos, const char* final_pos, bool& en_passant_attack) const; // 
        bool check_move_not_null(const char* initial_pos,  const char* final_pos) const;
        bool check_move_not_crossing(const char* initial_pos,  const char* final_pos) const;
        bool check_not_attacking_own_team(const char* initial_pos,  const char* final_pos) const;
        bool check_not_capturing_king(const char* final_pos) const;
        bool check_move_not_into_check(const char* initial_pos,  const char* final_pos) const;
        bool check_pawn_specific_moves(const char* initial_pos,
                                       const char* final_pos, 
                                       bool &en_passant_attack) const;

        // ========= Check/Check-Mate functions =======
        bool in_check(int turn);
        bool in_stalemate();
        
        // ========= Helper functions =========
        void find_king(int turn, char* king_pos) const; 
        bool has_legal_moves(char* piece_position) const;
        // ========= Flag setter =========
        void set_flags(const char* initial_pos,  const char* final_pos);

        void submitMove(const char* initial_pos,  const char* final_pos);
        void print_board();
        friend void operator<<(std::ostream& os, ChessBoard& chessboard){return chessboard.print_board();}
};

#endif