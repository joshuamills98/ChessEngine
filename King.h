#ifndef king_hpp
#define king_hpp

# include "ChessPiece.h"

class King : public ChessPiece {


    public:
        King(int colour);

        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♚" : "♔");}
        ~King() {};

};

#endif 
