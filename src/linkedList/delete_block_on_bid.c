#include "../../include/main_header.h"

void delete_block_on_bid(node_t **head, int nid)
{
    node_t *tmp = *head;
    node_t *prev;
    if (tmp != NULL && tmp->nid == nid)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->nid != nid)
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