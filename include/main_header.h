#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_


#include <unistd.h>
#include <stdlib.h>
#include<fcntl.h>

#include <stdio.h>
#include <stdbool.h>


// #ifndef TRANSACTION_STRUCT
// #define TRANSACTION_STRUCT
// struct transac_s
// {
//      nonce;
//     char gas_price[32];
//     char gaslimit[32];
//     char to[50];
//     int value;
//     char data[50];
//     char v[50];
//     char r[50];
//     char s[50];
// };
// typedef struct transac_s transac_t;
// #endif


#define BADCHAR (int)'?'
#define BADARG (int)':'
#define VALID_ARG "-l"
#define BLOCK_ADD 2760430684300
#define BLOCK_RM 104389829426
#define NODE_ADD 89046511139
#define NODE_RM 3367773885
#define SYNC 3545755
#define LS 3463
#define QUIT 3482191
#define TOKEN_MAX 7

#define INVITE_OBRACKET '['
#define INVITE_DIFF '-'
#define INVITE_SYNC 's'
#define INVITE_CLOSE "]>"

#define RESS_ERROR "1: no more resources available on computer\n"
#define NODE_EXIST_ERROR "2: this node already exists\n"
#define BLOCK_EXIST_ERROR "3: this block already exists\n"
#define NODE_DNT_EXIST "4: node doesn't exists\n"
#define BLOCK_DNT_EXIST "5: block doesn't exists\n"
#define CMD_ERROR "6: command not found\n"
#define OK "ok\n"
#define NOK "nok\n"
#define OPEN 1
#define CLOSE 0

#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node
{
    //hierarchy: n+1
    int index;
    struct node* head;
    // bool gates[TOKEN_MAX];
    int bid;
    int prev_bid;
    int nid;
    //hierarchy: n
    //int timestamp;
    //transac_t transaction;
    //char* proof[32];
    struct node* next;
};
typedef struct node node_t;
#endif


#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT
typedef struct s_my_getopt
{
    int index;
    int pos;
    bool* bool_arr; // activate each option
    int nbr_str;
    int path_pos;
    char** path_arr;
    int* file_size; //dummy
    bool* state;
    long long hash;
} my_getopt_t;
#endif



extern int READLINE_READ_SIZE;
extern char* rl_buff;
extern char* log_buff;

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
int size;
char** array;
} string_array;
#endif

//my_string.h

int my_strlen(char *str);                       // readline, my_split
char* my_strcat(char* str_dest, char* str_src); // readline,
char* my_strcpy(char* str_dest, char* str_src); // readline,
void* my_memset(void* ptr, char ch, int len);   // readline,
int my_strcmp(char* str1, char* str2);          // cmd_parse,
char* my_strchr(char* str, char ch);            // getopt,

//readline.h


char* my_readline(int fd);                      // main,
char* init_my_readline();                       // main,
int my_realloc_rl(int size);                    // readline,
int seek_newline(int size);                     // readline
bool is_newline(int size);                      // readline,

//my_unistd.h

void count_path_array(int argc, char** argv, my_getopt_t* getopt_ptr);
void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void fill_bool_array(bool* bool_arr, int len);
int flag_parser(int argc, char** argv, char* valid_args, my_getopt_t* getopt_ptr);
void free_opt(int argc, char** argv, my_getopt_t* getopt_ptr);
void init_getopt(my_getopt_t* getopt_ptr, char* valid_args);
int my_getopt(char** argv, char* valid_args, my_getopt_t* getopt_ptr);
void n_state(char opt, my_getopt_t *getopt_ptr, char** argv);

// hash strings
long long hash_string(char** arr, int arr_size, int arr_max_range);
bool check_hash(long long ash);

//my_split.h

void string_filter(char* str, char* delimiter, int len, int* bool_arr);
string_array* store_arrays(char** str_arr, int size_arr);
int get_array_size(int* bool_arr, int len);
void dynamic_malloc_split(char ** arr, int* bool_arr, int len , int size_arr);
void generate_array(char ** arr, char* str, int* bool_arr, int len);
char** dirty_split(char* str, int start_pos);

//node/block

node_t* create_block(node_t* head, int nid, int bid);
node_t* create_new_block(int value, int prev_bid);
node_t* create_new_node(int value, node_t *head);
node_t* insert_at_head(node_t** head, node_t* node_to_insert);

node_t* swap(node_t* head, int node_index1, int node_index2);

void print_and_free_llist(node_t* n_head);
void free_node(node_t* head);
int node_count(node_t *head);
node_t* create_cpy_block(node_t* block);
void sort_bid(node_t* node);
node_t* swap(node_t* head, int node_index1, int node_index2);
//void reverse_node_order(node_t** head);
node_t* sync_nodes(node_t* head);
bool is_block_on_chain(node_t* block_head, node_t* block);
void delete_node_on_nid(node_t **head, int nid);
void delete_block_on_bid(node_t **head, int nid);
int consensus_check(node_t* head);
void set_last_bid(node_t* head, int bid);
bool is_node_on_network(node_t* node_head, int nid);
bool check_bid(node_t* block_head, int bid);
bool is_block_on_network(node_t* node_head, int bid);
bool is_block_on_node(node_t* node_head, int nid, int bid);

//stdlib.h
int my_ctoi(char *string, size_t n);
char* itoa(int value, char* result, int base);
void my_revswap(char *ptr, char*ptr1, char tmp_char);

//my_blockchain

int count_cmd(char*str);
int quit_cmd(char* cmd, node_t* head);
node_t* add_block(node_t* head, my_getopt_t* getopt_ptr);
node_t* add_node(node_t* head, my_getopt_t* getopt_ptr);
void rm_block(node_t* head, my_getopt_t* getopt_ptr);
void rm_node(node_t* head, my_getopt_t* getopt_ptr);
char* print_llist_n_n1(node_t* n_head, bool state);
void test_print_list(node_t *head, char* str);
node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head);
// gandalf - unit test - log
int my_realloc_log(int size);
void catch_log(char* str);
void print_log();
#endif