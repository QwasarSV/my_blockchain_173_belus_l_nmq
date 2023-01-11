#include "../../include/main_header.h"

bool is_block_on_chain(node_t* block_head, node_t* block)
{
    node_t* tmp = block_head;

    while (tmp != NULL)
    {
        if (block->bid == tmp->bid)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}