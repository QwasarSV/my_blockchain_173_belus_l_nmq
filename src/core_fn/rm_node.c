#include <main_header.h>

int error_rm_node(node_t** head, my_getopt_t* getopt_ptr)
{
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(*head, nid) == false)
    {
        write(STDERR_FILENO, NODE_DNT_EXIST, my_strlen(NODE_DNT_EXIST));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void rm_node(node_t** head, my_getopt_t* getopt_ptr)
{
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    write(STDOUT_FILENO, OK, my_strlen(OK) );
    delete_node_on_nid(head, nid);
}