#ifndef __HEADERFILE_H_
#define __HEADERFILE_H_

#include <main_header.h>
//backup

void    serialize(node_t* head);
node_t* deserialize(node_t* head);
node_t* deserialize_block(node_t* head, char* str, int nid);

#endif