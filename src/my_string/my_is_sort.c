#include "../../include/main_header.h"

bool my_is_sort(int* int_array, int len) {
  
  int x = 0, i = 0, y = 0;

  if ( len == 0) {return true;} 
    while(i++ < len){
      if (int_array[x] >= int_array[x+1]) {x++;};
      if (int_array[y] <= int_array[y+1]) {y++;};
      if (x == len-1 || y == len-1) {return true;};
  }

  return false;
}