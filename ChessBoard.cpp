#include "ChessBoard.h"

// =========== Class Constructors/Destructors and Assignment Operator Overload ==========

ChessBoard::ChessBoard() : turn(white), game_over(false)
{
    this->create_all_pieces();
    std::cout << "A new chess game is started!" << std::endl;
}

ChessBoard::~ChessBoard()
{
    delete_all_pieces();
}

ChessBoard::ChessBoard(ChessBoard const& other_chessboard): turn(other_chessboard.turn), game_over(other_chessboard.game_over)
{
    create_blank_board();
    *this = other_chessboard; // Delegate to assignment operator
}

ChessBoard& ChessBoard::operator=(ChessBoard const& other_chessboard)
{
    if (this == &other_chessboard) // Self assignment guard
    {
        return *this;
    }

    this->delete_all_pieces(); // Clear current chessboard (if pieces exit)
    
    // Go through board and copy relevant pieces
    for (int row = '8'; row>= '1'; row--)
    {
        for (int column = 'A'; column<= 'H'; column++)
        {
            if (other_chessboard.chessboard['8'-row][column-'A'])
            {
                PieceType other_piece = other_chessboard.chessboard['8'-row][column-'A']->get_piece_type();
                int other_colour = other_chessboard.chessboard['8'-row][column-'A']->get_colour();
                switch(other_piece)
                {
                    case pawn:
                    this->chessboard['8'-row][column-'A'] = new Pawn(other_colour);
                    break;

                    case rook:
                    this->chessboard['8'-row][column-'A'] = new Rook(other_colour);
                    break;
                    
                    case knight:
                    this->chessboard['8'-row][column-'A'] = new Knight(other_colour);
                    break;                    

                    case bishop:
                    this->chessboard['8'-row][column-'A'] = new Bishop(other_colour);
                    break;

                    case queen:
                    this->chessboard['8'-row][column-'A'] = new Queen(other_colour);
                    break;

                    case king:
                    this->chessboard['8'-row][column-'A'] = new King(other_colour);
                }
            }
        }
    }
    this->turn = other_chessboard.turn; // Make turn = to other chessboard's turn
    this->game_over = other_chessboard.game_over;
    return *this;

}


// ======= Delete, create and reset ======
void ChessBoard::create_blank_board()
{
    for (int column = 'A'; column <= 'H'; column++)
    {
        for (int row = '8'; row>= '1'; row--)
        {
            chessboard['8'-row][column-'A'] = nullptr;
        }
    } 
}


void ChessBoard::create_all_pieces()
{
    // Initiate first two rows for white and black
    for (int colour = black; colour <= white; colour += white-black)
    {
        chessboard[colour == white ? 7 : 0][a_file] = new Rook(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][b_file] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][c_file] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][d_file] = new Queen(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][e_file] = new King(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][f_file] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][g_file] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][h_file] = new Rook(colour == black ? black : white);
        
        // Initiate pawns
        for (int column = 'A'; column <= 'H'; column++)
        {
            chessboard[colour == white ? 6 : 1][column - 'A'] = new Pawn(colour == black ? black : white);
        } 
    }

    // Instantiate the rest as nullptrs
    for (int column = 'A'; column <= 'H'; column++)
    {
        for (int row = '6'; row>= '3'; row--)
        {
            chessboard['8'-row][column-'A'] = nullptr;
        }
    } 
}

void ChessBoard::delete_all_pieces()
{
    for (int row = '8'; row>= '1'; row--)
    {
        for (int column = 'A'; column<= 'H'; column++)
        {
            if (chessboard['8'-row][column-'A'] != nullptr) // Delete all pieces if they actually exist
            {
                delete chessboard['8'-row][column-'A'];
                chessboard['8'-row][column-'A'] = nullptr;
            }
        }
    }
}

void ChessBoard::resetBoard()
{
    turn = white;
    game_over = false;

    // Wipe and create the board
    delete_all_pieces();
    create_all_pieces();

    std::cout << "A new chess game is started!" << std::endl;
}

// =========== Priority 1 Checks ============

bool ChessBoard::p1_checks(const char* initial_pos, const char* final_pos) const
{
    bool check = (check_move_format(initial_pos, final_pos) &&
                  check_move_targets_piece(initial_pos) &&
                  check_is_turn(initial_pos) &&
                  check_game_over());
    return check;
} 

bool ChessBoard::check_move_format(const char* initial_pos, const char* final_pos) const {
    // Check input is the right length
    if (strlen(initial_pos)>2 || strlen(final_pos)>2)
    {
        return false;
        std::cout << "Incorrect move format" << std::endl;
    }

    // Check input is correctly specified
    if (final_pos[0] > 'H' || final_pos[0] < 'A' || 
        final_pos[1] > '8' || final_pos[1] < '1'  ||
        initial_pos[0] > 'H' || initial_pos[0] < 'A' || 
        initial_pos[1] > '8' || initial_pos[1] < '1' )
        {
            std::cout << "Move not within bounds" << std::endl;

            return false;
        } 
    return true;
}

bool ChessBoard::check_move_targets_piece(const char* initial_pos) const
{
    if (!chessboard['8'-initial_pos[1]][initial_pos[0]-'A'])
    {
        std::cout << "There is no piece at position " << initial_pos << "!" << std::endl;
        return false;
    }
    return true;
}

bool ChessBoard::check_is_turn(const char* initial_pos) const
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';

    if (chessboard[row_0][column_0]->get_colour() == turn)
    {
        return true;
    }
    std::cout << "It is not "
              << (chessboard[row_0][column_0]->get_colour() == black ? "Black" : "White") 
              <<"'s turn to move!"
              << std::endl;
    return false;
}

bool ChessBoard::check_game_over() const
{
    if (this->game_over) {
        std::cout<< "Game is over, reset board to play again." << std::endl;
        return false;
    }
    return true;
}
// =========== Priority Level 2 Checks ============

bool ChessBoard::p2_checks(const char* initial_pos, const char* final_pos, bool& en_passant_attack) const
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    ChessPiece* chess_piece = chessboard[row_0][column_0];
    bool check =  (check_move_not_null(initial_pos, final_pos) &&
                   check_move_not_crossing(initial_pos, final_pos) &&
                   check_not_attacking_own_team(initial_pos, final_pos) &&
                   check_not_capturing_king(final_pos) &&
                   check_move_not_into_check(initial_pos, final_pos) &&
                   chess_piece->check_move(initial_pos, final_pos) && // Check move is valid based on individual piece logic
                   check_pawn_specific_moves(initial_pos, final_pos, en_passant_attack));
    return check;
}

bool ChessBoard::check_move_not_null(const char* initial_pos,  const char* final_pos) const
{
    if ((initial_pos[0] == final_pos[0]) && (initial_pos[1] == final_pos[1]))
    {
        return false;
    }
    return true;
}

bool ChessBoard::check_move_not_crossing(const char* initial_pos,  const char* final_pos) const
{
    int column_0 = initial_pos[0] - 'A';
    int row_0 = '8' - initial_pos[1];
    int column_1 = final_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];

    if (chessboard[row_0][column_0]->get_piece_type() != knight) // Knights can move through pieces
    {
        // If the piece is not a knight, there are only three types of moves that can skip more than one space
        // 1: Diagonal Movement. 2: Vertical Movement. 3: Horizontal Movement
        // All of these moves can be described by a vector

        if ((abs(row_1-row_0)>1) || (abs(column_1-column_0)>1)) // If moving at least one position away
        {
            int dist_row = row_1-row_0; // Distance travlled by row
            int dist_column = column_1-column_0; // Distance travlled by column

            int direction_column = (dist_column == 0 ? 0 : dist_column/abs(dist_column)); // +1 or -1
            int direction_row = (dist_row == 0 ? 0 : dist_row/abs(dist_row)); // +1 or -1

            // If moving diagonally, the distance travlled can use either distance change for row or column
            // This logic ensures that the number of steps is dictated by the change in column or row (depending on which is not 0)
            int num_steps = (dist_row != 0 ? abs(dist_row)-1 : abs(dist_column)-1); 

            // Walk back through intermediate positions along direction change
            for(int i = 1; i<=num_steps; i++)
            {                
                if(chessboard[row_0+i*direction_row][column_0+i*direction_column]!=nullptr) // If a piece exists between 
                {
                    return false;
                }
            }
            return true;
        }
    }
    return true;
}

bool ChessBoard::check_not_attacking_own_team(const char* initial_pos,  const char* final_pos) const
{
    int column_0 = initial_pos[0] - 'A';
    int row_0 = '8' - initial_pos[1];
    int column_1 = final_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];

    if (chessboard[row_1][column_1] && // If piece actually exists at attacked position
        chessboard[row_0][column_0]->get_colour() == chessboard[row_1][column_1]->get_colour()) // Same colour as attacking piece
    {
        return false;
    }
    return true;
}

bool ChessBoard::check_not_capturing_king(const char* final_pos) const
{
    int column_1 = final_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    if (chessboard[row_1][column_1] &&
        chessboard[row_1][column_1]->get_piece_type() == king)
    {
        return false;
    }
    return true;
}

bool ChessBoard::check_move_not_into_check(const char* initial_pos, const char* final_pos) const
{
    // Create a completely new board with similar set up
    
    ChessBoard new_board = *this;

    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';
    
    // Make move
    if (new_board.chessboard[row_1][column_1]){delete new_board.chessboard[row_1][column_1];}
    new_board.chessboard[row_1][column_1] = new_board.chessboard[row_0][column_0];
    new_board.chessboard[row_0][column_0] = nullptr;

    // Check if new board is in check with given config handing turn over
    if (new_board.in_check(turn))
    {
        // std::cout << "Can't move into check" << std::endl;
        return false;
    }
    return true;
}

bool ChessBoard::check_pawn_specific_moves(const char* initial_pos,  
                            const char* final_pos,
                            bool &en_passant_attack) const
{

    int column_0 = initial_pos[0] - 'A';
    int row_0 = '8' - initial_pos[1];
    int column_1 = final_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];

    ChessPiece* chess_piece = chessboard[row_0][column_0];
    if (chess_piece->get_piece_type() == pawn) // If piece is a pawn
    {
        if ((column_1 == column_0)) // If moving directly ahead
        {
            if (chessboard[row_1][column_1]) // If capturing a piece directly in front
            {
                return false; // Not allowed to capture a piece directly in front
            }
            return true;
        }
        else if ((abs(column_1-column_0)== abs(row_1-row_0))) // If moving diagonally 
        {
            // There are only two cases in which a diagonal move is acceptable
            // Case 1: A direct capture
            if (chessboard[row_1][column_1])
            {
                return true;
            }

            // Case 2: An "en passant"
            // First get the position of the piece under threat from En Passant
            int attacked_piece_row = row_1 + chess_piece->get_colour(); // It will be one row behind the attacking piece
            int attacked_piece_column = column_1;                       // The colour is used to dictate the directionality

            if (!chessboard[attacked_piece_row][attacked_piece_column]) // If no piece exists there
            {
                return false;
            }

            ChessPiece* attacked_piece = chessboard[attacked_piece_row][attacked_piece_column];

            if ((attacked_piece->get_piece_type() == pawn) &&  // If piece being attacked is a pawn
                (attacked_piece->get_en_passant_flag()) && // If it is in a position where en passant is applicable
                !chessboard[row_1][column_1]) // If no piece is in the way
            {
                en_passant_attack = true; // Set en passant flag to be used in the submitMove function
                return true;
            }
        }
    }
    return true; // If piece isn't a pawn then this function doesn't apply
}

// ========= Check/Check-Mate functions =======

bool ChessBoard::in_check(int turn) const // In check will check if given colour is in check
{

    // Get position of king
    char king_pos[2];
    find_king(turn, king_pos);

    char attacker_pos[2];

    // Find all attackers and check if they can attack king
    for (int row = '8'; row>='1'; row--)
    {
        for (int column = 'A'; column<='H'; column++)
        {
            if ((chessboard['8'-row][column-'A']) && // If piece exists at given location
                (chessboard['8'-row][column-'A']->get_colour() == (turn == white ? black : white)) && // is attacking piece of other colour
                (chessboard['8'-row][column-'A']->get_piece_type() != king)) // King can't put another king in check 
            {
                ChessPiece* attacking_piece = chessboard['8'-row][column-'A'];
                attacker_pos[0] = column;
                attacker_pos[1] = row;
                
                // Case 1: Attacking piece is a pawn ( there is pawn specific functionality that needs to be addressed)
                if (attacking_piece->get_piece_type() == pawn) // Pawn can't check in every direction unlike other pieces
                {
                    int column_king = king_pos[0] - 'A';
                    int row_king = '8' - king_pos[1];
                    int column_attacker = attacker_pos[0] - 'A';
                    int row_attacker = '8' - attacker_pos[1];
                    if ((abs(column_king - column_attacker) == 1) && // If one column to the left or right
                        (row_king == row_attacker-attacking_piece->get_colour())) // Row above attacking piece (by direction)
                    {
                        return true;
                    }
                
                // Case 2: Attacking piece is not a pawn (All other pieces use normal moves to check)
                } else if (check_move_not_crossing(attacker_pos, king_pos) && // Check move is not blocked
                           attacking_piece->check_move(attacker_pos, king_pos)) // CHeck move is valid based on individual piece logic
                {
                    return true;
                }
            }
        }
    }
    return false; // If no attackers satisfy previous condition
}

bool ChessBoard::in_stalemate() // stalemate checked at the end of a player's turn
{ 
    
    // Check all other pieces of 
    char test_piece_pos[2];

    // Go through all pieces available to player and check if it
    // has any legal moves available to it
    for (int row = '8'; row>='1'; row--)
        {
            for (int column = 'A'; column<='H'; column++)
            {
                if ((chessboard['8'-row][column-'A']) && // Piece exists 
                    (chessboard['8'-row][column-'A']->get_colour() == turn)) // Colour is the colour of current turn
                    {
                        test_piece_pos[0] = column;
                        test_piece_pos[1] = row;
                        if (has_legal_moves(test_piece_pos))
                        {
                            return false;
                        }
                    }
            }
        }
        return true; // If you have checked every piece available to colour
                     // And no possible moves are available, it is a stalemate
}

// ========= Helper functions =========

void ChessBoard::find_king(int turn, char* king_pos) const
{
    // Get position of king
    for (int row = '8'; row>='1'; row--)
        {
            for (int column = 'A'; column<='H'; column++)
            {
                if ((chessboard['8'-row][column-'A']) && // Piece exists 
                    (chessboard['8'-row][column-'A']->get_colour() == turn) && // Is piece of colour in question
                    (chessboard['8'-row][column-'A']->get_piece_type() == king)) // Is a king
                {
                      king_pos[0] = column;
                      king_pos[1] = row;
                }
            }
        }
} 

bool ChessBoard::has_legal_moves(char* piece_position) const // Check if piece at given position has any legal moves
{
    char test_position[2]; 
    bool dummy_en_passant; // Unused
    for (int row = '8'; row>='1'; row--)
    {
        for (int column = 'A'; column<='H'; column++)
        {
            test_position[0] = column;
            test_position[1] = row;
            if (p2_checks(piece_position, test_position, dummy_en_passant)) // If piece passes all p2 checks for a single possible move
            {
                return true;
            }
        }
    } 
    return false; // If no possible moves are available to an individual piece
}


// ================== CASTLING FUNCTIONALITY ==================
// Castling checks are not contained within the priority 2 checks since castling can not be used 
// in any has_legal_move checks (it is not a way to avoid check)

bool ChessBoard::is_attempting_castle(const char* initial_pos, const char* final_pos) const
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    ChessPiece* chess_piece= chessboard[row_0][column_0];
    int piece_colour = chess_piece->get_colour();
                                                   // To determine if player is attempting castle:
    if ((chess_piece->get_piece_type() == king) && // Piece must be a king
        (row_0 == (piece_colour == white ? 7 : 0)) && // In given row
        (row_0 == row_1) && // Moving along row
        (column_0 == e_file) && // From the king's e file
        ((column_1 == c_file) || (column_1 == g_file))) // Between given columns
        {
            return true;
        }
    return false;
}

bool ChessBoard::check_castle(const char* initial_pos, const char* final_pos) const
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    ChessPiece* king_piece = chessboard[row_0][column_0];
    int colour = king_piece->get_colour();

    if (king_piece->get_castle_flag() && // If king can actually castle
        !chessboard[row_1][column_1]) // No piece exists at given position (not even enemy piece)
    {   
        // Case 1: short range castle
        if ((column_1 == g_file) && (row_1 == row_0))
        {   
            // If there is a rook in the h_file with which the king can castle
            if ((chessboard[colour == white ? 7 : 0][h_file]) &&
                (chessboard[colour == white ? 7 : 0][h_file]->get_piece_type() == rook) && // There is a rook
                (chessboard[colour == white ? 7 : 0][h_file]->get_colour() == colour) && // With same colour
                (chessboard[colour == white ? 7 : 0][h_file]->get_castle_flag()))
                 {
                    // If the king does not pass through check in order to castle
                    char test_pos[2];
                    test_pos[0] = initial_pos[0]+1;
                    test_pos[1] = initial_pos[1];  
                    if (check_move_not_into_check(initial_pos, test_pos))
                    {
                        return true;
                    }
                 }
        }

        // Case 2: long range castle
        else if ((column_1 == c_file) && (row_1 == row_0))
        {
            // If there is a rook in the a_file with which the king can castle
            if ((chessboard[colour == white ? 7 : 0][a_file]) && // Piece exists
                (chessboard[colour == white ? 7 : 0][a_file]->get_piece_type() == rook) && // is a rook
                (chessboard[colour == white ? 7 : 0][a_file]->get_colour() == colour) &&
                (chessboard[colour == white ? 7 : 0][a_file]->get_castle_flag())) // Has not yet moved
                 {
                    // If the king does not pass through check in order to castle
                    char test_pos[2];
                    test_pos[0] = initial_pos[0]-1;
                    test_pos[1] = initial_pos[1];  
                    if (check_move_not_into_check(initial_pos, test_pos))
                    {
                        return true;
                    }
                 }
        }
    }
    return false;
}

void ChessBoard::perform_castle(const char* initial_pos, const char* final_pos)
{
    int row_0 = '8' - initial_pos[1];
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';
    int piece_colour = chessboard[row_0][column_0]->get_colour();
    CastleType castle_type;

    // Case 1: short range castle
    if ((column_1 == g_file) && (row_1 == row_0))
    {
        ChessPiece* rook_piece = chessboard[row_0][h_file];
        chessboard[row_0][f_file] = rook_piece; // Move rook piece over king
        chessboard[row_0][h_file] = nullptr; 
        rook_piece->set_castle_flag();
        castle_type = short_castle;
    }
    // Case 2: Long range castle
    else if ((column_1 == c_file) && (row_1 == row_0))
    {
        ChessPiece* rook_piece = chessboard[row_0][a_file];
        chessboard[row_0][d_file] = rook_piece; // Move rook piece over king
        chessboard[row_0][a_file] = nullptr; 
        rook_piece->set_castle_flag();
        castle_type = long_castle;
    }

    std::cout << (piece_colour == white ? "White " : "Black ")
              << "performs a "
              << (castle_type == short_castle ? "short-" : "long-")
              << "range castle" << std::endl;    
}

// ========= Flag setter =========

void ChessBoard::set_flags(const char* initial_pos,  const char* final_pos)
{
    int row_0 = '8' - initial_pos[1]; 
    int column_0 = initial_pos[0] - 'A';
    int row_1 = '8' - final_pos[1];
    int column_1 = final_pos[0] - 'A';

    // En Passsant Flag

    ChessPiece* chess_piece = chessboard[row_1][column_1];
    if (chess_piece->get_piece_type() == pawn) // If a pawn has been moved
    {
        if (!chess_piece->get_move_flag()) // If this is the Pawn's first move
        {
            chess_piece->set_move_flag(); //Set the move flag to true

            // If pawn has moved two squares and can be taken 
            // through en passant (can only happen on first move)
            if ((abs(row_1-row_0) ==2) && (column_1==column_0))
            {
                chess_piece->set_en_passant_flag(true);
            }
        }
        else{ // If pawn had already moved prior to check
        chess_piece->set_en_passant_flag(false); // It can no longer be captured via EP
        }
    }

    // King in check flag

    char king_pos[2];
    find_king(this->turn, king_pos); // Find this turn's king position
    int col_king = king_pos[0] - 'A';
    int row_king = '8'- king_pos[1];
    chessboard[row_king][col_king]->set_check_flag(in_check(this->turn));

    // Rook and king castle flag

    if(chess_piece->get_piece_type() == king || chess_piece->get_piece_type() == rook) // If either of the rook or king have moved 
    {
        chess_piece->set_castle_flag(); // Turn off ability to castle if either king or rook have moved
    }
}


// ================= END OF MOVE FUNCTIONS =================

void ChessBoard::submitMove(const char* initial_pos,  const char* final_pos)
{
    if (p1_checks(initial_pos, final_pos)) // If move meets first priority level checks
    {
        bool en_passant_attack = false;
        bool capture_flag = false;
        int row_0 = '8' - initial_pos[1]; 
        int column_0 = initial_pos[0] - 'A';
        int row_1 = '8' - final_pos[1];
        int column_1 = final_pos[0] - 'A';
        ChessPiece* chess_piece = chessboard[row_0][column_0];
        ChessPiece* attacked_position = chessboard[row_1][column_1];

        if (p2_checks(initial_pos, final_pos, en_passant_attack)) // Perform priority level 2 checks
            {

            // Case 1: If attempting a castle
            if (is_attempting_castle(initial_pos, final_pos)) 
            {
                if (check_castle(initial_pos, final_pos))
                {
                    perform_castle(initial_pos, final_pos);
                    chessboard[row_1][column_1] = chessboard[row_0][column_0]; // Point to previous piece
                    chessboard[row_0][column_0] = nullptr; // Set initial piece to null
                    handle_end_of_move(initial_pos, final_pos);
                }
                else{
                    std::cout<< "Invalid castle" << std::endl;
                    return;
                }
            }  
            else // Case 2: Not performing a castle
            {    
                std::string captured_piece_name;
                int captured_colour; 

                // ===== Capturing Moves ======
                if (en_passant_attack) // Case 1: En Passant
                {
                    capture_flag = true;
                    captured_piece_name = piece_lookup(chessboard[row_1+chess_piece->get_colour()][column_1]->get_piece_type());
                    captured_colour = chessboard[row_1+chess_piece->get_colour()][column_1]->get_colour();
                    delete chessboard[row_1+chess_piece->get_colour()][column_1];
                    chessboard[row_1+chess_piece->get_colour()][column_1] = nullptr;
                }
                else if (attacked_position) // Case 2: Direct Capture of another piece (can not do en passant as well)
                {
                    capture_flag = true;
                    captured_piece_name = piece_lookup(chessboard[row_1][column_1]->get_piece_type());
                    captured_colour = chessboard[row_1][column_1]->get_colour();
                    delete chessboard[row_1][column_1];
                }

                chessboard[row_1][column_1] = chessboard[row_0][column_0]; // Point to previous piece

                // Print out statements
                std::cout << (chessboard[row_0][column_0]->get_colour() == black ? "Black" : "White")
                            << "'s " << piece_lookup(chessboard[row_0][column_0]->get_piece_type()) 
                            << " moves from " << initial_pos
                            << " to " << final_pos;
                if (capture_flag) // Print capture statement
                {
                    std::cout << " taking " 
                              << (captured_colour == black ? "Black's " : "White's ")
                              << captured_piece_name;
                }
                std::cout << std::endl;

                chessboard[row_0][column_0] = nullptr; // Set initial piece to null
                handle_end_of_move(initial_pos, final_pos);
            }
            }
            else
            {
            // Print out priority level 2 error messages
            std::cout << (turn == black ? "Black's " : "White's ")
                      << piece_lookup(chess_piece->get_piece_type())
                      << " cannot move to "
                      << final_pos << "!" << std::endl;
            }
    }

}

void ChessBoard::handle_end_of_move(const char* initial_pos,  const char* final_pos)
{
    // print_board(); // Print turn if successful 

    this->turn = (this->turn == white ? black : white); // Change over turns
    set_flags(initial_pos, final_pos); // Set respective piece flags

    // ===== Check, stalemeate and Chekmate
    if (in_check(this->turn)) // Check the other colour is in check after your move
    {
        if (in_stalemate()) // Case 1: A stalemate (a stalemate while cheked == a checkmate)
        {
            std::cout << (this->turn == white ? "White " : "Black ") 
                      << "is in checkmate"
                    //   << ", " 
                    //   << (this->turn == black ? "White " : "Black ") 
                    //   << "wins!" 
                      << std::endl;
            this->game_over = true;
            return;
        }
        else // Case 2: A normal check
        {
            std::cout << (this->turn == white ? "White " : "Black ") 
                      << "is in check" << std::endl;
        }
    }
    else if (in_stalemate()) // Else check for a stalemate on its own
    {
    std::cout << "Game ends in a draw due to a stalemate on " 
            << (this->turn == white ? "White's" : "Black's")
            << " King" << std::endl;
    this->game_over = true;
    return;
    }
}

void ChessBoard::print_board()
{
    
    std::cout << "  ";
    for (int column = 'A'; column <= 'H'; column++)
    {
        std::cout << "  " << (char)column << " ";
    }
    std::cout << std::endl;
    std::cout << "  ";
    for (int column = 'A'; column <= 'H'; column++)
    {
        std::cout << "----";
    }
    std::cout << "-" << std::endl;

    for (int row = '8'; row >= '1'; row--)
    {
        std::cout << (char)row << " ";
        for (int column = 'A'; column <= 'H'; column++)
        {
            auto piece = chessboard['8'-row][column-'A'];

            // Unicode error on wsl with white pawn, quick fix...
            bool unicode_pawn_flag = false;
            if (piece != nullptr)
            {
            unicode_pawn_flag = ((piece->get_piece_type() == pawn) &&
                                      (piece->get_colour() == black));
            }

            std::cout << (!unicode_pawn_flag ? "| ": "|") 
                      << (piece != nullptr ? piece->get_piece_unicode() : " ") 
                      << " ";

        }
        std::cout << "| ";
        std::cout << std::endl;
        std::cout << "  ";
        for (int column = 'A'; column <= 'H'; column++)
        {
            std::cout << "----";
        }
        std::cout << "-" << std::endl;
    }
}