#include <main_header.h>

int error_rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    if (is_block_on_network(head, getopt_ptr->path_arr[2]) == false)
    {
        write(STDERR_FILENO, BLOCK_DNT_EXIST, my_strlen(BLOCK_DNT_EXIST));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head;
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    while (tmp != NULL && tmp->nid != nid)
    {
        tmp = tmp->next;
    }
    write(STDOUT_FILENO, OK, my_strlen(OK));
    delete_block_on_bid(&tmp->head, getopt_ptr->path_arr[2]);
}