#ifndef CHESSCONSTANTS_H
#define CHESSCONSTANTS_H

#define black -1
#define white 1

#include <string.h>
#include <stdio.h>
#include <iostream>


void convert_position_to_int(const char* position, int converted_output[]);

enum PieceType {pawn, bishop, knight, rook, queen, king};

std::string piece_lookup(int piece_type);

#endif