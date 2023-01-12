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

bool check_bid(node_t* block_head, int bid)
{
    node_t* tmp = block_head;

    while (tmp != NULL)
    {
        if (bid == tmp->bid)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool is_node_on_network(node_t* node_head, int nid)
{
    node_t* tmp = node_head;

    while (tmp != NULL)
    {
        if (nid == tmp->nid)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool is_block_on_network(node_t* node_head, int nid, int bid)
{
    node_t* tmp = node_head;
    bool result = false;

    while (tmp != NULL)
    {
        check_bid(tmp->head, bid);
        tmp = tmp->next;
    }
    return false;
}

bool is_block_on_node(node_t* node_head, int nid, int bid)
{
    node_t* tmp = node_head;

    while (tmp != NULL)
    {
        if (nid == tmp->nid)
        {
            return check_bid(tmp->head, bid);
        }
        tmp = tmp->next;
    }
    return false;
}