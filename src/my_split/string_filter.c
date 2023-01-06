#include "../../include/main_header.h"


void string_filter(char* str, char* delimiter, int len, int* bool_arr) {
        
    int state = true, index_00 = 0, index_01 = 0;

    while(index_00 < len){
        state = true;
        while(delimiter[index_01] != '\0'){
            if(str[index_00] == delimiter[index_01]){
                state = false;
            }
            index_01++;
        
        }
        index_01 = 0;
        if(state == true){
            bool_arr[index_00] = true;
        } else {
            bool_arr[index_00] = false;
        }
        index_00++;
    }
}