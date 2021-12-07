#ifndef chessconstants_hpp
#define chessconstants_hpp

#define black -1
#define white 1

#include <string>
#include <stdio.h>
#include <iostream>

enum PieceType {pawn, bishop, knight, rook, queen, king};

std::string piece_lookup(int piece_type);
#endif