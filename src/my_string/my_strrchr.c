#include "../../include/main_header.h"


char* my_strrchr(char* str1, char ch)
{
    int len = my_strlen(str1), index = 0;
    while(str1[len-index] != ch)
    {
        index += 1;
        if(index == len) {
            return NULL;
        }
    }
    return &str1[len-index];
}