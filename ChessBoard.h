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
        // High level priority check 'p1' must be passed for any move to be considered 
        bool p1_checks(const char* initial_pos, const char* final_pos) const; // 
        
        // Check move entry is formatted correctly
        bool check_move_format(const char* initial_pos, const char* final_pos) const; 
        
        // Check it is the turn of submission
        bool check_is_turn(const char* initial_pos) const; 

        // Check the move actually targets an individual piece
        bool check_move_targets_piece(const char* initial_pos) const; 

        // Check the game is not already over
        bool check_game_over() const;

        // =========== Priority 2 Checks ============
        // Priority 2 level checks are game specific but equally must be passed 
        bool p2_checks(const char* initial_pos, const char* final_pos, bool& en_passant_attack) const;

        // Check piece is not being moved its own position
        bool check_move_not_null(const char* initial_pos,  const char* final_pos) const;

        // Check the move doesn't force a piece cross over another piece (provided it is not a knight)
        bool check_move_not_crossing(const char* initial_pos,  const char* final_pos) const;

        bool check_not_attacking_own_team(const char* initial_pos,  const char* final_pos) const;

        bool check_not_capturing_king(const char* final_pos) const;

        // Check the move doesn't send your own king into check 
        bool check_move_not_into_check(const char* initial_pos,  const char* final_pos) const;
        bool check_pawn_specific_moves(const char* initial_pos,
                                       const char* final_pos, 
                                       bool &en_passant_attack) const;

        // ========= Check/Check-Mate functions =======
        bool in_check(int turn) const;
        bool in_stalemate();
        
        // ========= Extra Helper functions =========
        void find_king(int turn, char* king_pos) const; 
        bool has_legal_moves(char* piece_position) const;

        // ========= Castling Functionality ==========
        bool is_attempting_castle(const char* initial_pos, const char* final_pos) const;
        bool check_castle(const char* initial_pos, const char* final_pos) const;
        void perform_castle(const char* initial_pos, const char* final_pos);

        // ========= Flag setter =========
        void set_flags(const char* initial_pos,  const char* final_pos);

        // ========= Submission ==========
        void submitMove(const char* initial_pos,  const char* final_pos);
        void handle_end_of_move(const char* initial_pos,  const char* final_pos);
        void print_board();

        // ========= Operator Overloads ========
        friend void operator<<(std::ostream& os, ChessBoard& chessboard){return chessboard.print_board();}
};

#endif