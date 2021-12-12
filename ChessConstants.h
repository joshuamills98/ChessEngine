#ifndef CHESSCONSTANTS_H
#define CHESSCONSTANTS_H

#define black -1
#define white 1

#include <string.h>
#include <stdio.h>
#include <iostream>

enum PieceType {pawn, bishop, knight, rook, queen, king};

enum File {a_file, b_file, c_file, d_file, e_file, f_file, g_file, h_file};

enum CastleType {short_castle, long_castle};

// Function to get the string name of a piece given the type of piece
std::string piece_lookup(PieceType piece_type); 

#endif