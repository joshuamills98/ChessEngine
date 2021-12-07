#ifndef bishop_hpp
#define bishop_hpp

# include "ChessPiece.h"

class Bishop : public ChessPiece {

    public:
        Bishop(int colour);
        bool check_move(const char* initial_pos,
                        const char* final_pos) override; 
        std::string get_piece_unicode() const override {return (colour == black ? "♝" : "♗");}
        ~Bishop() {};

};

#endif // !1
