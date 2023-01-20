#include <main_header.h>

node_t* create_cpy_block(node_t* block)
{
    node_t* result = malloc(sizeof(node_t));
    result->prev_bid = block->prev_bid;
    result->index = block->index;
    result->bid = block->bid;
    result->next = NULL;
    result->head = NULL;
    return result;
}