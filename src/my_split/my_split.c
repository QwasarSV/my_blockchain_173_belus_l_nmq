#include "../../include/main_header.h"

string_array* my_split(char* str, char* delimiter)
{
    if(str[0] == '\0')
    {
        return EXIT_SUCCESS;
    }

    int len = my_strlen(str); 

    int *bool_arr = malloc(sizeof(int)*(len+1));

    string_filter(str,delimiter, len, bool_arr);

    int size_arr = get_array_size(bool_arr, len);

    char **arr = malloc(sizeof(char*)*(size_arr+1));

    //check_bool(len, bool_arr, str);

    dynamic_malloc_split(arr, bool_arr, len , size_arr);

    generate_array(arr, str, bool_arr, len);

    //free(bool_arr);

    return store_arrays(arr, size_arr);
}