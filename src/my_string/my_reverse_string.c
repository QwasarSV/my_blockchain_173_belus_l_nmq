#include "../../include/main_header.h"


void my_reverse_string(char* str)
{
    char *start = str, *end = str, tmp_char;
    int len = my_strlen(str), index = 0, rev = 0;
    rev = len-1;   
    while(index < (len/2))
    {    
        tmp_char = end[rev];
        end[rev] = start[index];
        start[index] = tmp_char;
        index++;
        rev--; 
    }
}
