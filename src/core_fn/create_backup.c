#include <main_header.h>

void create_backup(node_t* head)
{
    node_t* tmp = head;
    int fd = 0;
    fd = open("backup.txt", O_CREAT | O_APPEND, 0644);
    while (head != NULL)
    {
        write(fd, head, sizeof(head));    
        head = head->next;
    }
    close(fd);
}