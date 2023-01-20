#include <main_header.h>
#include <string.h>
#define MAX_TOKENS 20

int find_ch(char* str)
{
    int index = 0;
    while (str[index] != ' ' && str[index] != '\0')
    {
            index += 1;
    }
    return index;
}

char** dirty_split(char* str, int start_pos)
{
    char* tmp = str;
    char** tokens = malloc(sizeof(char*)*MAX_TOKENS);
    char* start = str;
    char* end;
    int index = start_pos;
    int pos = 0;
    while ((end = strchr(start, ' ')) != NULL)
    {
        pos = find_ch(start);
        start[pos] = '\0';
        tokens[index] = start;
        index += 1;
        start = end + 1;
    }
    tokens[index] = start;
    return tokens;
}

// int main(void)
// {
//     char str[] = "add node 10 -l";
//     char** tokens = NULL;
//     tokens = dirty_split(str);

//     int index = 0;
//     while (index < 4)
//     {
//         printf("%s\n",tokens[index]);
//         index +=1;
//     }

//     return 0;
// }