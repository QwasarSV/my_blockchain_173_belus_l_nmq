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

#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node
{
    //hierarchy: n+1
    int index;
    struct node* head;

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
} my_getopt_t;
#endif


#define BADCHAR (int)'?'
#define BADARG (int)':'
#define VALID_ARG "-l"
#define ADD "add"
#define LS "ls"
#define REMOVE "rm"
#define SYNC "sync"
#define QUIT "quit"
#define BLOCK "block"
#define NODE "node"

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

extern int READLINE_READ_SIZE;
extern char* rl_buff;

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

//my_split.h

void string_filter(char* str, char* delimiter, int len, int* bool_arr);
string_array* store_arrays(char** str_arr, int size_arr);
int get_array_size(int* bool_arr, int len);
void dynamic_malloc_split(char ** arr, int* bool_arr, int len , int size_arr);
void generate_array(char ** arr, char* str, int* bool_arr, int len);
char** dirty_split(char* str, int start_pos);

//node/block

node_t* create_new_block(int value);
node_t* create_new_node(int value, node_t *head);
node_t* insert_at_head(node_t** head, node_t* node_to_insert);
void test_print_list(node_t *head);
node_t* swap(node_t* head, int node_index1, int node_index2);
void print_and_free_llist(node_t* n_head);
void free_node(node_t* head);


//stdlib.h
int my_ctoi(char *string, size_t n);


#endif