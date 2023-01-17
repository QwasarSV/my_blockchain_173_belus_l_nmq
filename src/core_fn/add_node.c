#include "../../include/main_header.h"


node_t* add_node(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = NULL;
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(head, nid))
    {
        printf("nok\n");
        write(STDIN_FILENO, NODE_EXIST_ERROR, my_strlen(NODE_EXIST_ERROR));
    }
    else
    {
        char str[4] = OK;
        // catch_log(str);
        write(STDIN_FILENO, str, my_strlen(str) + 1);
        tmp = create_new_node(nid, NULL);
        head = insert_at_head(&head, tmp);
        head->prev_bid = consensus_check(head);
    }
    return head;
}