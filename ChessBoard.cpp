#include "ChessBoard.h"

// =========== Class Constructor/Destructor ==========

ChessBoard::ChessBoard() : turn(white)
{
    std::cout << "A new chess game is started!" << std::endl;
    // Initiate first two rows for white and black
    for (int colour = black; colour <= white; colour += white-black)
    {
        chessboard[colour == white ? 7 : 0][0] = new Rook(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][1] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][2] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][3] = new Queen(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][4] = new King(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][5] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][6] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][7] = new Rook(colour == black ? black : white);
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
            if (chessboard['8'-row][column-'A'] != nullptr)
            {
                // std::cout<< "Deleting piece at " <<(char)column << (char)row << std::endl;
                delete chessboard['8'-row][column-'A'];
                chessboard['8'-row][column-'A'] = nullptr;
            }
        }
    }
}
void ChessBoard::create_all_pieces()
{
    // Initiate first two rows for white and black
    for (int colour = black; colour <= white; colour += white-black)
    {
        chessboard[colour == white ? 7 : 0][0] = new Rook(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][1] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][2] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][3] = new Queen(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][4] = new King(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][5] = new Bishop(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][6] = new Knight(colour == black ? black : white);
        chessboard[colour == white ? 7 : 0][7] = new Rook(colour == black ? black : white);
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

ChessBoard::~ChessBoard()
{
    std::cout << "Deconstructing chessboard" << std::endl;
    delete_all_pieces();
}

void ChessBoard::resetBoard()
{
    delete_all_pieces();
    create_all_pieces();
}
// =========== High level mnove checks ============

bool ChessBoard::check_move_main(const char* initial_pos, const char* final_pos) const
{
    bool check = (check_move_format(initial_pos, final_pos) &&
                  check_move_targets_piece(initial_pos) &&
                  check_is_turn(initial_pos) &&
                  check_move_not_null(initial_pos, final_pos) &&
                  check_move_not_crossing(initial_pos, final_pos))
                  ;
    return check;
}

bool ChessBoard::check_move_format(const char* initial_pos, const char* final_pos) const {
    // Check input is the right length
    if (strlen(initial_pos)>2 || strlen(final_pos)>2)
    {
        return false;
        std::cout << "Incorrect move format" << std::endl;
    }
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

bool ChessBoard::check_move_not_null(const char* initial_pos,  const char* final_pos) const
{
    if ((initial_pos[0] == final_pos[0]) && (initial_pos[1] == final_pos[1]))
    {
        std::cout << "Can not move from " 
                  << initial_pos << " to "
                  << final_pos << " (Final position must be different)"
                  << std::endl;
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
        // Case 1: Diagonal movement 
        if ((abs(row_1-row_0)>1) || (abs(column_1-column_0)>1)) // Moving at least one position away
        {
            int dist_row = row_1-row_0;
            int dist_column = column_1-column_0;

            int direction_column = (dist_column == 0 ? 0 : dist_column/abs(dist_column)); // +1 or -1
            int direction_row = (dist_row == 0 ? 0 : dist_row/abs(dist_row)); // +1 or -1
    
            int num_steps = (dist_row != 0 ? dist_row-1 : dist_column-1);

            // Walk back through intermediate positions
            for(int i = 1; i<=num_steps; i++)
            {                
                if(chessboard[row_0+i*direction_row][column_0+i*direction_column]!=nullptr) // If a piece exists between 
                {
                    int piecetype = chessboard[row_0][column_0]->get_piece_type();
                    int piececolour = chessboard[row_0][column_0]->get_colour();
                    std::cout << (piececolour==black ? "Black's " : "White's ")
                              << piece_lookup(piecetype) << " cannot move to "
                              << final_pos << "!" << std::endl;
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

    if (chessboard[row_0][column_0]->get_colour() == chessboard[row_1][column_1]->get_colour())
    {
        int piecetype = chessboard[row_0][column_0]->get_piece_type();
        int piececolour = chessboard[row_0][column_0]->get_colour();
        std::cout << (piececolour==black ? "Black's " : "White's ")
            << piece_lookup(piecetype) << " cannot move to "
            << final_pos << "!" << std::endl;
        return false;
    }
    return true;
}

// ========= Move submission ========

void ChessBoard::submitMove(const char* initial_pos,  const char* final_pos)
{
    bool capture_flag = false;
    if (check_move_main(initial_pos, final_pos))
        {
            int row_0 = '8' - initial_pos[1]; 
            int column_0 = initial_pos[0] - 'A';
            int row_1 = '8' - final_pos[1];
            int column_1 = final_pos[0] - 'A';

            if (chessboard[row_0][column_0]->check_move(initial_pos, final_pos))
            {
                std::string captured_piece_name;
                int captured_colour;
                if (chessboard[row_1][column_1]!=nullptr) // If killing another piece
                {
                    capture_flag = true;
                    captured_piece_name = piece_lookup(chessboard[row_1][column_1]->get_piece_type());
                    captured_colour = chessboard[row_1][column_1]->get_colour();
                    delete chessboard[row_1][column_1];
                }
                chessboard[row_1][column_1]= chessboard[row_0][column_0];

                std::cout << (chessboard[row_0][column_0]->get_colour() == black ? "Black" : "White")
                        << "'s " << piece_lookup(chessboard[row_0][column_0]->get_piece_type()) 
                        << " moves from " << initial_pos
                        << " to " << final_pos;
                        
                        if (capture_flag)
                        {
                        std::cout << " taking " 
                                  << (captured_colour == black ? "Black's " : "White's ")
                                  << captured_piece_name;
                        }
                    
                        std::cout << std::endl;


                chessboard[row_0][column_0] = nullptr;
                print_board();
                this->turn = (this->turn == white ? black : white);
            }
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

