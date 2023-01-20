#ifndef __HEADERFILE_M_
#define __HEADERFILE_M_

#include <main_header.h>


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



//node/block

node_t* create_block(node_t* head, int nid, int bid);
node_t* create_new_block(int value, int prev_bid);
node_t* create_new_node(int value, node_t *head);
node_t* insert_at_head(node_t** head, node_t* node_to_insert);
node_t* insert_after_node(node_t* node_to_insert, node_t* new_node);
void reverse_node_order(node_t** head);
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

#endif