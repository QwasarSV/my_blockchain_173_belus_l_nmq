#include <main_header.h>

// test function to recode
// int diff_block(node_t* head) 
// {
//     int min_count = __INT_MAX__; 
//     int max_count = 0;
//     int count = 0;
//     node_t* tmp = head;
//     while (tmp != NULL)
//     {
//         count = node_count(tmp->head);    
//         if (count > max_count)
//         {
//             max_count = count;
//         }
//         if (count < min_count)
//         {
//             min_count = count;
//         }
//         tmp = tmp->next;
//     }
//     return max_count - min_count;
// }