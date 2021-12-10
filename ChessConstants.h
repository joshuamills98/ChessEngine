#ifndef CHESSCONSTANTS_H
#define CHESSCONSTANTS_H

#define black -1
#define white 1

#include <string.h>
#include <stdio.h>
#include <iostream>


void convert_position_to_int(const char* position, int converted_output[]);

enum PieceType {pawn, bishop, knight, rook, queen, king};

enum File {a_file, b_file, c_file, d_file, e_file, f_file, g_file, h_file};

std::string piece_lookup(int piece_type);

#endif