#include <unistd.h>
#include "../../include/main_header.h"


void rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head; 
    int bid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_block_on_network(head, bid) == false)
    {
        write(STDOUT_FILENO, NOK, my_strlen(NOK));
        write(STDOUT_FILENO, BLOCK_DNT_EXIST, my_strlen(NODE_DNT_EXIST));
    }
    else
    {
        while(tmp != NULL)
        {
            delete_block_on_bid(&tmp->head, bid);
            tmp = tmp->next;
        }
    }
}