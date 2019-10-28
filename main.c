#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
  //creating a list
  printf("%s\n", "Printing empty list:");
  struct node * list_head;
  list_head = NULL;
  print_list(list_head);

  printf("\n%s\n", "Adding numbers 0-9 to list:");
  int nums[] = {0,1,2,3,4,5,6,7,8,9};
  for (int i = 0; i < 10; i++) {
    list_head = insert_front(list_head,nums[i]);
  }
  print_list(list_head);

  printf("\n%s\n", "Testing remove:");
  printf("%s\n", "Removing 9:");
  list_head = remove_node(list_head, 9);
  print_list(list_head);
  printf("%s\n", "Removing 4:");
  list_head = remove_node(list_head, 4);
  print_list(list_head);
  printf("%s\n", "Removing 0:");
  list_head = remove_node(list_head, 0);
  print_list(list_head);
  printf("%s\n", "Removing -1:");
  list_head = remove_node(list_head, -1);
  print_list(list_head);

  printf("\n%s\n%s ", "Testing free list:", "Current list:");
  free_list(list_head);
  list_head = NULL;
  printf("Printing list: ");
  print_list(list_head);
  printf("\n");

  return 0;
}
