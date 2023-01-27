#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_

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
#define BLOCK_ADD   2060171284
#define BLOCK_RM    1112149039
#define NODE_ADD    233620095
#define NODE_RM     381772396
#define SYNC        1491471
#define LS          146
#define QUIT        2044899
#define TOKEN_MAX   7

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
#define OK "OK\n"
#define NOK "NOK\n"

//my_split.h

char** dirty_split(char* str, int start_pos, char ch);

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
void rm_node(node_t** head, my_getopt_t* getopt_ptr);
void print_llist_n_n1(node_t* n_head, bool state);
void test_print_list(node_t *head, char* str);
node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head);

// gandalf - unit test - log
int my_realloc_log(int size);
void catch_log(char* str);
void print_log();
int diff_block_02(node_t* head);

//backup
void serialize(node_t* head);
node_t* deserialize(node_t* head);
#endif
