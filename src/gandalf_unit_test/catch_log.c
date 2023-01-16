#include "../../include/main_header.h"

char* log_buff;
int my_realloc_log(int size)
{
    int size_buff = 0;
    if (log_buff != NULL)
    {
        size_buff = my_strlen(log_buff) + 1;
    }
    char tmp_buff[size_buff];
    int total_size = size + size_buff;
    if (log_buff != NULL)
    {
        my_strcpy(tmp_buff, log_buff);
        free(log_buff);
    }    
    log_buff = malloc(total_size + 1);
    my_strcpy(log_buff, tmp_buff);
    log_buff[size_buff] = '\0';
    return size + size_buff;
}

void catch_log(char* str)
{
    int size = 0;
    size = my_strlen(str);
    my_realloc_log(size);
    my_strcat(log_buff, str);
}

void print_log()
{
    printf("%s\n",log_buff);
}