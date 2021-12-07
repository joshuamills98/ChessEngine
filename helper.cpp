#include "helper.h"

void convert_position_to_int(const char* position, int converted_output[])
{
    converted_output[0] = *position - 'A' + 1;
    converted_output[1] = *(position+1) - '1' + 1;
}