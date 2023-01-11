#include "../../include/main_header.h"

void test_print_list(node_t *head)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->next != NULL)
        {
            printf(" %i,", tmp->bid);
        }
        else
        {
            printf(" %i", tmp->bid);
        }
        
        tmp = tmp->next;
    }
    // if (tmp == NULL)
    // {
    //     // printf("null\n");
    // }
}
        // printf("p%d-", tmp->prev_bid);