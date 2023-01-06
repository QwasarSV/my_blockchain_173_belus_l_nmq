#include "../../include/main_header.h"

void generate_array(char ** arr, char* str, int* bool_arr, int len)
{
    int counter=0;
    int row = 0;
    int column = 0;
    
    while (counter < len)
    {
        if (bool_arr[counter] == true)
        {
            arr[row][column] = str[counter];
            column++;
        } 
        else
        if (bool_arr[counter] == false && column > 0)
        {
            arr[row][column] = '\0';
            row++;
            column = 0;
        }
        counter++;
    }
    arr[row][column] = '\0';
}