#include <main_header.h>

int error_add_node(node_t* head, my_getopt_t* getopt_ptr)
{
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(head, nid))
    {
        write(STDERR_FILENO, NODE_EXIST_ERROR, my_strlen(NODE_EXIST_ERROR));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

node_t* add_node(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = NULL;
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
        write(STDOUT_FILENO, OK, my_strlen(OK));
        tmp = create_new_node(nid, NULL);
        head = insert_at_head(&head, tmp);
        // char buff[SIZE_BID] = {'\0'};
        // consensus_check(head, buff);
        // my_strcpy(head->prev_bid, buff);
    return head;
}