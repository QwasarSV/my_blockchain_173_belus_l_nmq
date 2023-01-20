#include <main_header.h>

char* my_strdup(char* str)
{    
    if(str == NULL)
    {
        return NULL;
    }
    int len = my_strlen(str);
    char str_dest[] = {0};
    char *ptr = malloc(sizeof(char)*len+1);
    ptr = my_strcpy(str_dest, str);
    return ptr;
}