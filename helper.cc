int* convert_position_to_int(const char* position)
{
    int converted_position[2];
    converted_position[0] = *position - 'A' + 1;
    converted_position[1] = *(position+1) - '1' + 1;
    return converted_position; 
}