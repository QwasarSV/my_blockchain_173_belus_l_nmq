#include <main_header.h>

int error_add_block(node_t* head, my_getopt_t* getopt_ptr)
{
    if (getopt_ptr->path_arr[3][0] == '*')
    {
        return EXIT_SUCCESS;
    }
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    if (is_node_on_network(head, nid) == false)
    {
        write(STDERR_FILENO, NODE_DNT_EXIST, NODE_DNT_EXIST_LEN);
        return EXIT_FAILURE;
    }
    if (is_block_on_chain_02(head, nid, getopt_ptr->path_arr[2]))
    {
        write(STDERR_FILENO,BLOCK_EXIST_ERROR, BLOCK_EXIST_ERROR_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

node_t* add_block(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head; 
    if (getopt_ptr->path_arr[3][0] == '*')
    {
        while (tmp != NULL)
        {
            head = create_block(head, tmp->nid, getopt_ptr->path_arr[2]);
            set_last_bid(head, getopt_ptr->path_arr[2]);
            tmp = tmp->next;
        }
    }
    else
    {
        int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
        write(STDOUT_FILENO, OK, OK_SIZE);
        head = create_block(head, nid, getopt_ptr->path_arr[2]);
        set_last_bid(head, getopt_ptr->path_arr[2]);
    }
    return head;
}
   // if (is_block_on_network(head, bid))
    // {
    //     write(STDOUT_FILENO, NOK, my_strlen(NOK));
    //     write(STDOUT_FILENO, BLOCK_EXIST_ERROR, my_strlen(BLOCK_EXIST_ERROR));
    // }
    // else