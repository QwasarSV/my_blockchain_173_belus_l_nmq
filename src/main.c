#include "../include/main_header.h"

int count_cmd(char*str)
{
    int index = 0;
    int counter = 0;
    while (str[index] != '\0')
    {
        if (str[index] == ' ')
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
}

node_t* create_block(node_t* head, int nid, int bid)
{
    node_t* tmp = head;
    node_t* tmp_block= NULL;
    while (tmp != NULL)
    {
        if (tmp->index == nid)
        {
            tmp_block = create_new_block(bid);
            tmp->head = insert_at_head(&tmp->head, tmp_block);
        }
        tmp = tmp->next;
    }
    return head;
}

void set_last_bid(node_t* head, int bid)
{
    node_t* tmp = head;
    while(tmp != NULL)
    {
        tmp->prev_bid = bid;
        tmp = tmp->next;
    }
}

int consensus_check(node_t* head)
{
  int max_count = 0;
  int max_element = 0;
  int current_count = 0;
  int current_element = 0;

  // Initialize linked list with some data

  // Iterate through linked list and find the element with the highest frequency
  node_t *tmp = head;
  while (tmp != NULL) {
    if (tmp->prev_bid == current_element) {
      current_count++;
    } else {
      if (current_count > max_count) {
        max_count = current_count;
        max_element = current_element;
      }
      current_element = tmp->prev_bid;
      current_count = 1;
    }
    tmp = tmp->next;
  }

  // Check the count for the last element
  if (current_count > max_count) {
    max_count = current_count;
    max_element = current_element;
  }
  return max_element;
}
    // if(head->next == NULL)
    // {
    //     return EXIT_FAILURE;
    // }

    // node_t* tmp = head;
    // int counter_bid = 0;
    // int counter_node = 0;
    // tmp = tmp->next;
    // int tmp_bid = tmp->prev_bid;
    // while (tmp != NULL)
    // {
    //     if (tmp->prev_bid == tmp_bid)
    //     {
    //         counter_bid += 1;
    //     }
    //     tmp_bid = tmp->prev_bid;
    //     counter_node += 1;
    //     tmp = tmp->next;
    // }
    // return consensus_prototype(counter_node, counter_bid);


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
        else if (my_strcmp(getopt_ptr->path_arr[1], BLOCK) == 0)
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
        // run rm and end function
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
        printf("main.c - readline_str : |%s|\n", str);
        cmd_count = count_cmd(str) + 2;
        tokens = dirty_split(str , 1); //draw me like one of your argv!
        flag_parser(cmd_count, tokens, VALID_ARG, getopt_ptr);
        node = execute_cmd(getopt_ptr, node);
        if (my_strcmp(getopt_ptr->path_arr[0], QUIT) == 0)
        {
            printf("%s\n",getopt_ptr->path_arr[0]);
            print_and_free_llist(node);
            fd = -1;
        }
        free_opt(cmd_count, tokens, getopt_ptr);
        free(tokens);
        free(str);
    }
    //free_readline();
    return 0;
}
        // printf("main.c - cmd_count : %i\n",cmd_count);
        // printf("main.c - cmd_total : %i\n",cmd_count_total);
        // printf("main.c - tokens    :%s\n",tokens[0]);
        // printf("main.c - tokens    :%s\n",tokens[1]);
        // printf("main.c - tokens    :%s\n",tokens[2]);