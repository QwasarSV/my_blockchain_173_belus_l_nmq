#include "../../include/main_header.h"

string_array* store_arrays(char** str_arr, int size_arr)
{
    int row = 0;
    string_array* string_ptr = malloc(sizeof(string_array));
    string_ptr->size = size_arr;    
    string_ptr->array = str_arr;
    return string_ptr;
}