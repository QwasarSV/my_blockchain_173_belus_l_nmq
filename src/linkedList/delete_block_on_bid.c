#include "../../include/main_header.h"

void delete_block_on_bid(node_t **head, int bid)
{
    node_t *tmp = *head;
    node_t *prev;
    if (tmp != NULL && tmp->nid == bid)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->bid != bid)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}