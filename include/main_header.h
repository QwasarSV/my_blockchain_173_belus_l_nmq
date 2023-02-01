#ifndef __HEADERFILE_A_
#define __HEADERFILE_A_


#define SIZE_BID 32
#define SIZE_NID 12

#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node
{
    struct node* head;
    struct node* next;
    int index;
    char bid[SIZE_BID];
    char prev_bid[SIZE_BID];
    int nid;
};
typedef struct node node_t;
#endif




#include <unistd.h>
#include <stdlib.h>
#include<fcntl.h>

#include <stdio.h>
#include <stdbool.h>

#include <my_unistd.h>
#include <linked_list.h>
#include <my_string.h>
#include <my_readline.h>
#include <my_blockchain.h>
#include <sys_check.h>



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


#define BADCHAR                 (int)'?'
#define BADARG                  (int)':'
#define VALID_ARG               "-l"
#define BLOCK_ADD               2060171284
#define BLOCK_RM                1112149039
#define NODE_ADD                233620095
#define NODE_RM                 381772396
#define SYNC                    1491471
#define LS                      146
#define QUIT                    2044899
#define TOKEN_MAX               7
#define INVITE_OBRACKET         '['
#define INVITE_DIFF             '-'
#define INVITE_SYNC             's'
#define INVITE_CLOSE            "]>"


#define RESS_ERROR              "NOK\n1: no more resources available on computer\n"
#define RESS_ERROR_LEN 
#define NODE_EXIST_ERROR        "NOK\n2: this node already exists\n"
#define NODE_EXIST_ERROR_LEN    32
#define BLOCK_EXIST_ERROR       "NOK\n3: this block already exists\n"
#define BLOCK_EXIST_ERROR_LEN 
#define NODE_DNT_EXIST          "NOK\n4: node doesn't exists\n"
#define NODE_DNT_EXIST_LEN      27
#define BLOCK_DNT_EXIST         "NOK\n5: block doesn't exists\n"
#define BLOCK_DNT_EXIST_LEN     28
#define CMD_ERROR               "NOK\n6: command not found\n"
#define OK                      "OK\n"

//my_split.h

char** dirty_split(char* str, int start_pos, char ch);

//stdlib.h
int my_ctoi(char *string, size_t n);
char* itoa(int value, char* result, int base);
void my_revswap(char *ptr, char*ptr1, char tmp_char);

//my_blockchain

int count_cmd(char*str);
node_t* add_block(node_t* head, my_getopt_t* getopt_ptr);
node_t* add_node(node_t* head, my_getopt_t* getopt_ptr);
void rm_block(node_t* head, my_getopt_t* getopt_ptr);
void rm_node(node_t** head, my_getopt_t* getopt_ptr);
void print_llist_n_n1(node_t* n_head, bool state);
char* print_block(node_t *head, char* str);
node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head);
node_t* sync_nodes(node_t* head);


void* my_realloc(void* buff, size_t size);
// gandalf - unit test - log
int diff_block_02(node_t* head);

//error management 
int error_handler(my_getopt_t* getopt_ptr, node_t* head);
int error_add_block(node_t* head, my_getopt_t* getopt_ptr);
int error_add_node(node_t* head, my_getopt_t* getopt_ptr);
int error_rm_block(node_t* head, my_getopt_t* getopt_ptr);
int error_rm_node(node_t** head, my_getopt_t* getopt_ptr);

//backup
void serialize(node_t* head);
node_t* deserialize(node_t* head);
#endif