#include "../../include/main_header.h"


long long hash_string(char** arr, int arr_size, int arr_max_range)
{
    int key = 31;
    int index = 0;
    int jndex = 0;
    long long hash = 0;
    while (index < arr_size && index < arr_max_range)
    {
        jndex = 0;
        while(arr[index][jndex] != '\0')
        {
            hash = key * hash + arr[index][jndex];
            jndex += 1;
        }
        index += 1;
    }
    return hash;
}

bool check_hash(long long ash)
{
    long long hash = 0;
    int index = 0;
    long long TOKEN_LIST[TOKEN_MAX] = {BLOCK_ADD, BLOCK_RM, NODE_ADD, NODE_RM, SYNC, QUIT};
    while (index < TOKEN_MAX)
    {
        if (hash == TOKEN_LIST[index])
        {
            return true;
        } 
        index += 1;
    }
    return false;
}