#include "../../include/main_header.h"

node_t* swap(node_t* head, int node_index1, int node_index2)
{
    node_t* curr1 = head, * prev1 = NULL, * curr2 = head, * prev2 = NULL, * tmp = NULL;
    

    if (node_index1 == node_index2)
    {
        return head;
    }

    if (node_index2 == head->index)
    {   
        node_index2 = node_index1;
        node_index1 = head->index;
    }

    while (curr2 != NULL &&  curr2->index != node_index2)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (head->index != node_index1 && head->index != node_index2)
    {
        while(curr1 != NULL &&  curr1->index != node_index1)
        {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        prev1->next = curr2;
    }
    prev2->next = curr1;
    tmp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = tmp;
    if (head->index == node_index1 || head->index == node_index2)
    {
        head = curr2;
    }
    return head;
}