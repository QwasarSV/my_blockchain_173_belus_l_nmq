#ifndef __HEADERFILE_D_
#define __HEADERFILE_D_

#include <main_header.h>

extern int READLINE_READ_SIZE;
extern char* rl_buff;
extern char* log_buff;

//readline.h

char* my_readline(int fd);                      // main,
char* init_my_readline();                       // main,
int my_realloc_rl(int size);                    // readline,
int seek_newline(int size);                     // readline
bool is_newline(int size);                      // readline,

#endif