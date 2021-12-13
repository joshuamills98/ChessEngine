#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "ChessConstants.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"

class ChessBoard 
{
    // The chessboard class operates the functionality describing the chessboard

    // DATA MEMBERS:
    // ChessPiece* chessboard - the chessboard composed of 8x8 squares each containing pointers to a chesspiece object
    // int turn - integer describing whether the turn is white or black
    // bool game_over - a boolean that specifies the games state.

    // FUNCTION CATEGORIES:
    // DELETE, CREATE AND RESET: functions to initialize and reset the board
    // PRIORITY 1 CHECKS: These checks determine the higher level validity of any entry to the board
    // PRIORITY 2 CHECKS: These checks determine validity of move based on state of the board
    // the p2_check will be used within other functions
    // CHECK/CHECKMATE: Check if board is in check or check mate given state of chessboard object
    // EXTRA HELPER FUNCTIONS: Useful functions to help with other functions
    // CASTLING FUNCTIONALITY: Checks and procedures for carrying out a castle move
    // END OF MOVE FUNCTIONS: Functions that take place after succesful move submission

    // ADDITIONAL INFO:
    // Most functions take on a char* initial_pos which is a character array specifying the position - column then row (e.g. "A2" or "E5")

    ChessPiece* chessboard[8][8];
    int turn; // Whose turn is it?
    bool game_over;

    public:
        ChessBoard();
        ~ChessBoard();
        ChessBoard(ChessBoard const& other_chessboard); // Copy Constructor
        ChessBoard &operator=(ChessBoard const& other); // Overloaded Assignment Operator

        // ================== DELETE, CREATE AND RESET ==================
        void create_blank_board();
        void delete_all_pieces();
        void create_all_pieces();
        void resetBoard();

        // ====================== PRIORITY 1 CHECKS ======================

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

        // ====================== PRIORITY 2 CHECKS ======================

        // Priority 2 level checks are game specific but equally must be passed 
        bool p2_checks(const char* initial_pos, const char* final_pos, bool& en_passant_attack) const;

        // Check piece is not being moved its own position
        bool check_move_not_null(const char* initial_pos,  const char* final_pos) const;

        // Check the move doesn't force a piece to cross over another piece (provided it is not a knight)
        bool check_move_not_crossing(const char* initial_pos,  const char* final_pos) const;

        bool check_not_attacking_own_team(const char* initial_pos,  const char* final_pos) const;

        bool check_not_capturing_king(const char* final_pos) const;

        // Check the move doesn't send your own king into check 
        bool check_move_not_into_check(const char* initial_pos,  const char* final_pos) const;
        
        // Check pawn specific moves are satisfied, namely the initial double step performed and the en passant
        bool check_pawn_specific_moves(const char* initial_pos,
                                       const char* final_pos, 
                                       bool &en_passant_attack) const;

        // ==================== CHECK/CHECKMATE  ======================

        // Determine if the colour/turn is in check 
        bool in_check(int turn) const; 

        bool in_stalemate();
        
        // ================== EXTRA HELPER FUNCTIONS ==================

        // Find the king of the given colour/turn, pass in an empty pointer king_pos which
        // will be filled with the king's position 
        void find_king(int turn, char* king_pos) const; 

        // Check if given piece has any legal moves available to it
        bool has_legal_moves(char* piece_position) const;

        // ================== CASTLING FUNCTIONALITY ==================

        // Check if player is attempting to castle
        bool is_attempting_castle(const char* initial_pos, const char* final_pos) const;

        // Check if that castle is actually valid based on rules of chess
        bool check_castle(const char* initial_pos, const char* final_pos) const;

        // Perform the castle operation
        void perform_castle(const char* initial_pos, const char* final_pos);

        // ========= END OF MOVE FUNCTIONS ==========

        void submitMove(const char* initial_pos,  const char* final_pos);

        // Perform relevant checkmate checks, couts, flag setting at the end of the submission
        void handle_end_of_move(const char* initial_pos,  const char* final_pos);

        // Set flags relevant to the king, pawn and rook 
        void set_flags(const char* initial_pos,  const char* final_pos);
        void print_board();

        // ================== OPERATOR OVERLOAD ==================

        friend void operator<<(std::ostream& os, ChessBoard& chessboard){return chessboard.print_board();}
};

#endif