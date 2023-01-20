#include <main_header.h>


node_t* add_block(node_t* head, my_getopt_t* getopt_ptr)
{
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    int bid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(head, nid) == false)
    {
        write(STDOUT_FILENO, NOK, my_strlen(NOK));
        write(STDOUT_FILENO, NODE_DNT_EXIST, my_strlen(NODE_DNT_EXIST));
    }
    else
    // if (is_block_on_network(head, bid))
    // {
    //     write(STDOUT_FILENO, NOK, my_strlen(NOK));
    //     write(STDOUT_FILENO, BLOCK_EXIST_ERROR, my_strlen(BLOCK_EXIST_ERROR));
    // }
    // else
    {
        char str[4] = OK;
        catch_log(str);
        write(STDOUT_FILENO, str, my_strlen(str));
        head = create_block(head, nid, bid);
        set_last_bid(head, bid);
    }
    return head;
}