#include "../../include/main_header.h"

void set_last_bid(node_t* head, int bid)
{
    node_t* tmp = head;
    while(tmp != NULL)
    {
        tmp->prev_bid = bid;
        tmp = tmp->next;
    }
}