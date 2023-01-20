#include <main_header.h>
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

void invite_prmt(int val, int type) // test function to recode
{
    char buff[32] = {'\0'};
    itoa(val, buff, 10);
    int len = 4;
    len += my_strlen(buff) + 1;
    char str[len];
    my_memset(str,'\0', len);
    str[0] = INVITE_OBRACKET;
    if (type == 1)
    {
        str[1] = INVITE_DIFF;
    }
    else
    {
        str[1] = INVITE_SYNC;
    }
    my_strcat(str, buff);
    my_strcat(str, INVITE_CLOSE);
    write(STDOUT_FILENO, str, my_strlen(str));
    // catch_log(str);
}
    // char str[35] = {'\0'};
    // strcat(str, INVITE_01);
    // if (type == 1)
    // {
    //     strcat(str, INVITE_DIFF);
    // }
    // else
    // {
    //     strcat(str, INVITE_SYNC);
    // }
    // char buff[12];
    // their_itoa(val, buff, 10);
    // strcat(str, buff);
    // strcat(str, INVITE_OUT);
    // write(STDIN_FILENO, str, 5);

void new_cmd(node_t* head) // test function to recode
{
    if (head == NULL)
    {
        invite_prmt(0, 0);
        return;
    }
    int diff = diff_block_02(head);
    int count = node_count(head);
    if (count >= 0 && diff == 0)
    {
        invite_prmt(count, 0);
    }
    else
    {
        invite_prmt(count, 1);
    }
}




int main(void) 
{
    int cmd_count = 0;
    int fd = STDIN_FILENO;
    node_t* node = NULL;
    my_getopt_t* getopt_ptr = NULL;
    //open("backup.txt", O_CREAT || O_APPEND, 0644);
    // while ((initiale_size = read(fd, &node, READLINE_READ_SIZE)))
    // {
    // }
    char* str = NULL;
    char** tokens = NULL;
    write(STDOUT_FILENO, "[s0]>", 5); // TO IMPLEMENT WITH BACKUP RECOVERY/ CREATION
    // catch_log("[s0]>ok\n");
    init_my_readline();
    while ((str = my_readline(fd)) != NULL)
    {
        getopt_ptr = malloc(sizeof(my_getopt_t));
        init_getopt(getopt_ptr, VALID_ARG);
        cmd_count = count_cmd(str) + 2;
        tokens = dirty_split(str , 1); //draw me like one of your argv!
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        node = execute_cmd(getopt_ptr, node);
        // if (node == NULL)
        // {
        //     return EXIT_SUCCESS;
        // }
        // fd = quit_cmd(getopt_ptr->path_arr[0], node);
        if (getopt_ptr->exit_status == true)
        {
           fd = -1;
        }
        else
        {
            new_cmd(node);
        }
        free_opt(cmd_count, tokens, getopt_ptr);
        free(tokens);
        free(str);
    }
    // print_log();
    //free_readline();
    return EXIT_SUCCESS;
}
        // printf("main.c - readline_str : |%s|\n", str);
        // printf("main.c - cmd_count : %i\n",cmd_count);
        // printf("main.c - cmd_total : %i\n",cmd_count_total);
        // printf("main.c - tokens    :%s\n",tokens[0]);
        // printf("main.c - tokens    :%s\n",tokens[1]);
        // printf("main.c - tokens    :%s\n",tokens[2]);