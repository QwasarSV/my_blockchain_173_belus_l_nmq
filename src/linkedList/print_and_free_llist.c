#include "../../include/main_header.h"
#include <stdio.h>

void print_and_free_llist(node_t* n_head) //, my_getopt_t *getopt_ptr
{
    int index = 0;
    // if (getopt_ptr->nbr_str > 1)
    // {
    //     reverse_node_order(&n_head);
    // }
    node_t *tmp = n_head; 
    while (tmp != NULL)
    {
        // if (getopt_ptr->nbr_str > 1)
        // {
            printf("node %i:\n",tmp->index);
        // } 
        if (tmp->head != NULL)
        {
            test_print_list(tmp->head);
        }
        free_node(tmp->head);
        tmp = tmp->next;
        //index += 1;
        // if(index < getopt_ptr->nbr_str)
        // {
            printf("\n");
        // }
    }
    free_node(n_head);
}