#include "../../include/main_header.h"
#include <string.h>
void test_print_list(node_t *head, char* str)
{
    char buff[32] = {'\0'};
    int size = 0;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->next != NULL)
        {
            itoa(tmp->bid, buff, 10);
            size = my_strlen(str);
            str[size] = ' ';
            strcat(str, buff);
            size += my_strlen(buff) +1;
            str[size] = ',';
            // printf(" %i,", tmp->bid);
        }
        else
        {
            itoa(tmp->bid, buff, 10);
            size = my_strlen(str);
            str[size] = ' ';
            strcat(str, buff);
            // printf(" %i", tmp->bid);
        }
        bzero(buff, my_strlen(buff));
        tmp = tmp->next;
    }
    // if (tmp == NULL)
    // {
    //     // printf("null\n");
    // }
}
        // printf("p%d-", tmp->prev_bid);