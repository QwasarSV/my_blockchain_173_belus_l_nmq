#include "../../include/main_header.h"

int consensus_check(node_t* head)
{
  int max_count = 0;
  int max_element = 0;
  int current_count = 0;
  int current_element = 0;

  // Iterate through linked list and find the element with the highest frequency
  node_t *tmp = head;
  while (tmp != NULL)
  {
    if (tmp->prev_bid == current_element)
    {
      current_count++;
    }
    else
    {
      if (current_count > max_count)
      {
        max_count = current_count;
        max_element = current_element;
      }
      current_element = tmp->prev_bid;
      current_count = 1;
    }
    tmp = tmp->next;
  }

  // Check the count for the last element
  if (current_count > max_count)
  {
    max_count = current_count;
    max_element = current_element;
  }
  return max_element;
}