#include "../../include/main_header.h"


void rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    int bid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    if (is_block_on_network(head, bid) == false)
    {
        write(STDIN_FILENO, NOK, my_strlen(NOK));
        write(STDIN_FILENO, BLOCK_DNT_EXIST, my_strlen(NODE_DNT_EXIST));
    }
    else
    {
        delete_block_on_bid(&head, bid);
    }
}