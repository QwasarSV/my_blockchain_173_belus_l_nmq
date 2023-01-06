#include "../../include/main_header.h"

int get_array_size(int* bool_arr, int len)
{    
    int index = 0;
    int size = 1;
    int prev = bool_arr[0];

    while (index < len)
    {
        if (prev != bool_arr[index] && bool_arr[index] == true)
        {
            size += 1;
        }
        prev = bool_arr[index];   
        index += 1;
    }
    return size;
}