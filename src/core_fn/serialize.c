#include <main_header.h>
#include <string.h>

void serialize(node_t* head)
{
    int fd = 0 ;
    fd  = open("list.txt", O_CREAT | O_RDWR, 0644);
    char str[50] = {'\0'};
    char buff[32] = {'\0'};
    int size = 0;
    int count = 0;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        itoa(tmp->nid, buff, 10);
        strcat(str, buff);
        size = my_strlen(str);
        str[size] = ':';
        if (tmp->head != NULL )
        {
            test_print_list(tmp->head, str);
        }
        size = my_strlen(str);
        str[size] = '\n';
        bzero(buff, my_strlen(buff));
        tmp = tmp->next;
    }
    write(fd, str, my_strlen(str));
    close(fd);
}
    // node_t* tmp = head;
    // int fd = 0;
    // printf("creating backup...");
    // // fd = open("backup.txt", O_CREAT | O_APPEND, 0644);
    // FILE* file = fopen("list.txt", "w");
    // while (tmp != NULL)
    // {
    //     // write(fd, head, sizeof(head));
    //     fprintf(file,"%d, ", tmp->nid);
    //     tmp = tmp->next;
    // }
    // fclose(file);

node_t* deserialize_block(node_t* head, char* str, int nid)
{
	char** tokens = NULL;
	int count = count_cmd(str);
    tokens = dirty_split(str, 0, ',');
	int bid = 0;
	while (count >= 0)
	{
		bid = my_ctoi(tokens[count], my_strlen(tokens[count]));
		head = create_block(head, nid, bid);
		count -= 1;
	}
	free(tokens);
	return head;
}

node_t* deserialize(node_t* head)
{
    node_t* tmp = NULL;
    int fd = open("list.txt", O_RDONLY, 0644);
    if (fd == -1)
    {
        return head;
    }
    init_my_readline();
    char* str = NULL;
    char** tokens = NULL;
    int nid = 0;
    
    while ((str = my_readline(fd)) != NULL)
    {
   	    tokens = dirty_split(str, 1, ':');
	    nid = my_ctoi(tokens[1], strlen(tokens[1]));
	    tmp = create_new_node(nid, head);
        head = insert_after_node(head, tmp);	
	    head = deserialize_block(head, &tokens[2][1], nid);
	    free(tokens);
	    free(str);
    }
    close(fd);
    return head;
}