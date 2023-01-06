char* my_strncpy(char* str1, char* str2, int n)
{
    int index = 0;
    while(index < n)
    {
        str1[index] = str2[index];
    }
    str1[index] = '\0';
    return str1;
}