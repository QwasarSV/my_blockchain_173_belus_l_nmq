#include <main_header.h>

int error_handler(my_getopt_t* getopt_ptr, node_t* head)
{
    switch (getopt_ptr->hash)
    {
    case BLOCK_ADD:
        return error_add_block(head, getopt_ptr);
    case NODE_ADD:
        return error_add_node(head, getopt_ptr);
    case BLOCK_RM:
        return error_rm_block(head, getopt_ptr);
    case NODE_RM:
        return error_rm_node(&head, getopt_ptr);
    case LS:
        return EXIT_SUCCESS;
    case SYNC:
        return EXIT_SUCCESS;
    case QUIT:
        return EXIT_SUCCESS;
    default:
        write(STDERR_FILENO, CMD_ERROR, my_strlen(CMD_ERROR));
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}