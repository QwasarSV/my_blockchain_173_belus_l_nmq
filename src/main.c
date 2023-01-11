#include "../include/main_header.h"
#include <string.h>
// sync four part function
/*
    send block to all nodes
    check if block is on chain
    if not then copy it
    and then sort by bid
*/

    // printf("get_last_bid.c - prevbid : %i\n",tmp_bid);
    // printf("get_last_bid.c - currbid : %i\n",tmp->prev_bid);
    // printf("get_last_bid.c - counter_node : %i\n",counter_node);
    // printf("get_last_bid.c - counter_bid  : %i\n",counter_bid);

int diff_block(node_t* head) // test function to recode
{
    int min_count = __INT_MAX__; 
    int max_count = 0;
    int count = 0;
    node_t* tmp = head;
    while (tmp != NULL)
    {
        count = node_count(tmp->head);    
        if (count > max_count)
        {
            max_count = count;
        }
        if (count < min_count)
        {
            min_count = count;
        }
        tmp = tmp->next;
    }
    return max_count - min_count;
}

#define INVITE_01 "["
#define INVITE_DIFF "-"
#define INVITE_SYNC "s"
#define INVITE_OUT "]>"

void invite_prmt(int val, int type) // test function to recode
{
    char str[35] = {'\0'};
    strcat(str, INVITE_01);
    if (type == 1)
    {
        strcat(str, INVITE_DIFF);
    }
    else
    {
        strcat(str, INVITE_SYNC);
    }
    char buff[12];
    their_itoa(val, buff, 10);
    strcat(str, buff);
    strcat(str, INVITE_OUT);
    write(STDIN_FILENO, str, 5);
}

void new_cmd(node_t* head) // test function to recode
{
    int diff = diff_block(head);
    int count = node_count(head->head);
    if (count >= 0 && diff == 0)
    {
        invite_prmt(count, 0);
        //printf("[s%i]>", node_count(head->head));
    }
    else
    {
        invite_prmt(diff, 1);
        // printf("[-%i]>", diff);
    }
}

node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head)
{
    node_t* tmp = NULL;
    node_t* tmp_block= NULL;
    int nid = 0;
    int bid = 0;
    if (my_strcmp(getopt_ptr->path_arr[0], ADD) == 0)
    {   
        printf("OK\n");
        
        // printf("%s\n",getopt_ptr->path_arr[0]);
        if (my_strcmp(getopt_ptr->path_arr[1], NODE) == 0)
        {
            nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
            tmp = create_new_node(nid, NULL);
            head = insert_at_head(&head, tmp);
            head->prev_bid = consensus_check(head);
        }
        else
        if (my_strcmp(getopt_ptr->path_arr[1], BLOCK) == 0)
        {
            nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
            bid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
            head = create_block(head, nid, bid);
            set_last_bid(head, bid);
        }
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], REMOVE) == 0)
    {
        // printf("%s\n",getopt_ptr->path_arr[0]);
        if (my_strcmp(getopt_ptr->path_arr[1], NODE) == 0)
        {
            nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
            delete_node_on_nid(&head, nid);
        }
        else
        if (my_strcmp(getopt_ptr->path_arr[1], BLOCK) == 0)
        {
            bid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
            delete_block_on_bid(&head, bid);
        }
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], LS) == 0)
    {
        // printf("%s\n",getopt_ptr->path_arr[0]);
        print_llist_n_n1(head, getopt_ptr->bool_arr[0]);
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], SYNC) == 0)
    {
        printf("OK\n");
        head = sync_nodes(head);
        // printf("%s\n",getopt_ptr->path_arr[0]);
    }
    return head;
}

int main(void) 
{
    int cmd_count = 0;
    int fd = STDIN_FILENO;
    node_t* node;
    //open("backup.txt", O_CREAT || O_APPEND, 0644);
    // while ((initiale_size = read(fd, &node, READLINE_READ_SIZE)))
    // {
    // }
    char* str = NULL;
    char** tokens = NULL;
    write(fd, "[s0]>", 6);
    init_my_readline();
    while ((str = my_readline(fd)) != NULL)
    {
        my_getopt_t* getopt_ptr = malloc(sizeof(my_getopt_t));
        init_getopt(getopt_ptr, VALID_ARG);
        cmd_count = count_cmd(str) + 2;
        tokens = dirty_split(str , 1); //draw me like one of your argv!
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        node = execute_cmd(getopt_ptr, node);
        fd = quit_cmd(getopt_ptr->path_arr[0], node);
        if (fd != -1)
        {
            new_cmd(node);
        }
        free_opt(cmd_count, tokens, getopt_ptr);
        free(tokens);
        free(str);
    }
    //free_readline();
    return 0;
}
        // printf("main.c - readline_str : |%s|\n", str);
        // printf("main.c - cmd_count : %i\n",cmd_count);
        // printf("main.c - cmd_total : %i\n",cmd_count_total);
        // printf("main.c - tokens    :%s\n",tokens[0]);
        // printf("main.c - tokens    :%s\n",tokens[1]);
        // printf("main.c - tokens    :%s\n",tokens[2]);