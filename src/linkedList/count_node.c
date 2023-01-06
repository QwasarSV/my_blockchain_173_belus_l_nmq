#include "../../include/main_header.h"

int block_count(node_t *head)
{
    int count = 0;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        count += 1;
    }
    return count;
}