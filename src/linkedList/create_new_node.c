#include "../../include/main_header.h"

node_t* create_new_node(int value, node_t *head)
{
    node_t* n_result = malloc(sizeof(node_t));
    n_result->head = head;
    n_result->nid = value;
    n_result->prev_bid = -1;
    n_result->index = value;
    n_result->next = NULL;
    return n_result;
}