#include "../../include/main_header.h"
#include <string.h>
char* print_llist_n_n1(node_t* n_head, bool state)
{
    char str[50] = {'\0'};
    char buff[32] = {'\0'};
    int size = 0;
    int index = 0;
    node_t *tmp = n_head;
    while (tmp != NULL)
    {
        itoa(tmp->nid, buff, 10);
        strcat(str, buff);
        size = my_strlen(str);
        str[size] = ':';
        if (tmp->head != NULL && state == true)
        {
            test_print_list(tmp->head, str);
        }
        size = my_strlen(str);
        str[size] = '\n';
        bzero(buff, my_strlen(buff));
        tmp = tmp->next;
    }
    catch_log(str);
    write(STDIN_FILENO, str, my_strlen(str));
}
        //  printf("node %i ; last BID:%i\n",tmp->nid, tmp->prev_bid);