#include <main_header.h>

int error_rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    int bid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_block_on_network(head, bid) == false)
    {
        write(STDOUT_FILENO, NOK, my_strlen(NOK));
        write(STDOUT_FILENO, BLOCK_DNT_EXIST, my_strlen(NODE_DNT_EXIST));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head;
    int bid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    while(tmp != NULL && tmp->nid != nid)
    {
        tmp = tmp->next;
    }
    char str[4] = OK;
    write(STDOUT_FILENO, str, my_strlen(str) );
    delete_block_on_bid(&tmp->head, bid);
}