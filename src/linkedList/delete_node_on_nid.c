#include "../../include/main_header.h"

void delete_node_on_nid(node_t **head, int nid)
{
    node_t *tmp = *head;
    node_t *prev;
    if (tmp != NULL && tmp->nid == nid)
    {
        *head = tmp->next;
        free_node(tmp->head);
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
    free_node(tmp->head);
    free(tmp);
}


// void print_and_free_llist(node_t* n_head) //, my_getopt_t *getopt_ptr
// {
//     int index = 0;
//     node_t *tmp = n_head; 
//     while (tmp != NULL)
//     {
//         free_node(tmp->head);
//         tmp = tmp->next;
//     }
//     free_node(n_head);
// }


// {
//     node_t *tmp = *head;
//     node_t *prev;
//     free_node(tmp->head);
//     if (tmp != NULL && tmp->nid == nid)
//     {
//         *head = tmp->next;
//         free(tmp);
//         return;
//     }
//     while (tmp != NULL && tmp->nid != nid)
//     {
//         prev = tmp;
//         tmp = tmp->next;
//     }
//     if (tmp == NULL)
//     {
//         return;
//     }
//     prev->next = tmp->next;
//     free(tmp);
// }