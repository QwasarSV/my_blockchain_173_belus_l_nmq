#include "../../include/main_header.h"

int quit_cmd(char* cmd, node_t* head)
{
    if (my_strcmp(cmd, QUIT) == 0)
    {
        //printf("%s\n",cmd);
        print_and_free_llist(head);
        return -1;
    }
    return STDIN_FILENO;
}