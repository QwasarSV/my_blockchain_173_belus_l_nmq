#include "../include/main_header.h"



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

node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head)
{
    node_t* tmp = NULL;
    node_t* tmp_block= NULL;
    int nid = 0;
    int bid = 0;

    if (my_strcmp(getopt_ptr->path_arr[0], ADD) == 0)
    {
        nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
        printf("%s\n",getopt_ptr->path_arr[0]);
        if (my_strcmp(getopt_ptr->path_arr[1], NODE) == 0)
        {
            tmp = create_new_node(nid, NULL);
            head = insert_at_head(&head, tmp);
            head->prev_bid = consensus_check(head);
        }
        else
        if (my_strcmp(getopt_ptr->path_arr[1], BLOCK) == 0)
        {
            bid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
            head = create_block(head, nid, bid);
            set_last_bid(head, bid);
        }
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], REMOVE) == 0)
    {
        printf("%s\n",getopt_ptr->path_arr[0]);
        if (my_strcmp(getopt_ptr->path_arr[1], NODE) == 0)
        {
            nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
            delete_node_on_nid(&head, nid);
        }
        else
        if (my_strcmp(getopt_ptr->path_arr[1], BLOCK) == 0)
        {
        
        }
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], LS) == 0)
    {
        printf("%s\n",getopt_ptr->path_arr[0]);
        print_llist_n_n1(head, getopt_ptr->bool_arr[0]);
        // test_print_list(head);
        // run LS and end function
    }
    else
    if (my_strcmp(getopt_ptr->path_arr[0], SYNC) == 0)
    {
        head = sync_nodes(head);
        printf("%s\n",getopt_ptr->path_arr[0]);
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