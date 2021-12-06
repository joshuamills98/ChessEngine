#include <string.h>
#include <stdio.h>
#include <iostream>
#include "helper.h"

class ChessPiece {
    // Class to define a standard chess piece
    protected:
        int colour; // -1 = black, 1= white
        std::string piece_type;

    public:
        ChessPiece(int colour, std::string piece_type);

        virtual bool check_move(const char* initial_pos,
                                const char* final_pos,
                                bool const is_attacking) = 0;

        bool check_move_in_bounds(const char* final_pos) const;
};