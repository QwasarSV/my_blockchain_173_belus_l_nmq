#include "../../include/main_header.h"

int count_cmd(char*str)
{
    int index = 0;
    int counter = 0;
    while (str[index] != '\0')
    {
        if (str[index] == ' ')
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
}