#include "../../include/main_header.h"

node_t* create_new_block(int value)
{
    node_t* result = malloc(sizeof(node_t));
    result->index = value;
    result->next = NULL;
    result->head = NULL;
    return result;
}