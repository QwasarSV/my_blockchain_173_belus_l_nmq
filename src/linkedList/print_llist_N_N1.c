#include "../../include/main_header.h"
#include <stdio.h>

void print_llist_n_n1(node_t* n_head, bool state) //, my_getopt_t *getopt_ptr
{
    int index = 0;
    node_t *tmp = n_head; 
    while (tmp != NULL)
    {
        printf("%i:",tmp->nid);
        if (tmp->head != NULL && state == true)
        {
            test_print_list(tmp->head);
            
        }
        printf("\n");
        tmp = tmp->next;
    }
}

        //  printf("node %i ; last BID:%i\n",tmp->nid, tmp->prev_bid);