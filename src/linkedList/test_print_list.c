#include "../../include/main_header.h"

void test_print_list(node_t *head)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        printf("%d-", tmp->index);
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("null\n");
    }
}