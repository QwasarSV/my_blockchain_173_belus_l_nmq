#include <main_header.h>

node_t* create_new_block(int value, int prev_bid)
{
    node_t* result = malloc(sizeof(node_t));
    result->prev_bid = prev_bid;
    result->bid = value;
    result->next = NULL;
    result->head = NULL;
    return result;
}