#include <main_header.h>

void serialize(node_t* head)
{
    int fd = 0 ;
    fd  = open("list.txt", O_CREAT | O_RDWR, 0644);
    char* str = malloc(sizeof(char) * SIZE_NID);
    my_bzero(str, SIZE_NID);
    char buff[SIZE_NID] = {'\0'};
    int pos = 0;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        itoa(tmp->nid, buff, 10);
        my_strcat(str, buff);
        // size = my_strlen(str);
        // str[size ] = ':';
        my_strcat(str, ":");
        if (tmp->head != NULL )
        {
            str = print_block(tmp->head, str);
        }
        pos = my_strlen(str);
        str[pos] = '\n';
        my_bzero(buff, my_strlen(buff));
        tmp = tmp->next;
        if (tmp != NULL)
        {
            str = my_realloc(str, SIZE_NID);
        }
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
		head = create_block(head, nid, tokens[count]);
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
	    nid = my_ctoi(tokens[1], my_strlen(tokens[1]));
	    tmp = create_new_node(nid, head);
        head = insert_after_node(head, tmp);	
	    head = deserialize_block(head, &tokens[2][1], nid);
	    free(tokens);
	    free(str);
    }
    close(fd);
    return head;
}