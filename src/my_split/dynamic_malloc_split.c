#include "../../include/main_header.h"

void dynamic_malloc_split(char ** arr, int* bool_arr, int len , int size_arr)
{
    int row = 0;
    int index = 0;
    int counter = 0;

    while (index < len+1)
    {
        if (bool_arr[index] == true)
        {
            counter += 1;
        }
        else 
        if ((bool_arr[index] == false && counter > 0) || row == (size_arr))
        {
            arr[row] = malloc(sizeof(char)*(counter+1));
            counter = 0;
            row += 1;
        }
      index += 1;
    }
}