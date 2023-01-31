#ifndef __HEADERFILE_C_
#define __HEADERFILE_C_

#include <main_header.h>

//node/block

node_t* create_block(node_t* head, int nid, char* bid);
node_t* create_new_block(char* bid, char* prev_bid);
node_t* create_new_node(int nid, node_t *head);

node_t* insert_at_head(node_t** head, node_t* node_to_insert);
node_t* insert_after_node(node_t* node_to_insert, node_t* new_node);

void free_node(node_t* head);
void delete_node_on_nid(node_t **head, int nid);
void delete_block_on_bid(node_t** head, char* bid);

void reverse_node_order(node_t** head);
// node_t* swap(node_t* head, int node_index1, int node_index2);
// void sort_bid(node_t* node);
int node_count(node_t *head);

node_t* create_cpy_block(node_t* block);
void print_and_free_llist(node_t* n_head);

char* consensus_check(node_t* head, char* buff);
void set_last_bid(node_t* head, char* bid);
bool check_bid(node_t* block_head, char* bid);

bool is_block_on_chain(node_t* block_head, node_t* block);
bool is_node_on_network(node_t* node_head, int nid);
bool is_block_on_network(node_t* node_head, char* bid);
bool is_block_on_node(node_t* node_head, int nid, char* bid);

#endif