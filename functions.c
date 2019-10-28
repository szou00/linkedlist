#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node * n) {
  printf("%s", "[ ");
  while (n != NULL) {
    printf("%d ", n->i);
    n = n->next;
  }
  printf("%s\n", "]");
}


/**Should take a pointer to the existing list and the data to be added, create a new node and put it at the beginning of the list.
The second argument should match whatever data you contain in your nodes.
Returns a pointer to the beginning of the list.**/
struct node * insert_front(struct node * list_head, int x) {

  //allocate memory
  struct node* new_node;
  new_node = (struct node *)malloc(sizeof(list_head));

  new_node->i=x;
  new_node->next=list_head;

  list_head = new_node; //pointer points to the new beginning instead
  return list_head;
}

/**Should take a pointer to a list as a parameter and then go through the entire
list freeing each node and return a pointer to the beginning of the list (which should be NULL by then)**/
struct node * free_list(struct node *n){
  struct node * previous_node;
  struct node * current_node = n;
  print_list(n);

  while (current_node!=NULL) {
    previous_node = current_node;
    current_node = previous_node->next;
    printf("freeing node: %d\n", previous_node->i);
    free(previous_node);
    previous_node = NULL;
  }
  current_node = NULL;
  return n;
}

/**Remove the node containing data from the list pointed to by front.
If data is not in the list, nothing is changed.
Returns a pointer to the beginning of the list.**/
struct node * remove_node(struct node *front, int data) {
  struct node * current_node = front;
  struct node * previous_node;

  while (current_node!=NULL) { //if it hasn't reached the end of the list
    if (current_node->i == data) { //checks to see if the data within the node is equal to the one wanted
      // printf("equal, node has a value of: %d\n", current_node->i);
      if (current_node != front) { //if it's not the first node
        // printf("no, is not first node\n");
        previous_node->next = current_node->next; //the node before that node gets the next node
        return front; //returns the front of the list
      }
      // printf("yes, is first node\n");
      front = front->next; //if it is the first node, the "first" node becomes the node after the original first node
      return front; //return the new first node
    }
    //if it's not equal to the one wanted
    // printf("not found, moving on\n");
    previous_node = current_node; //the current node becomes the previous one
    current_node = current_node->next; //the next node becomes the current one
  }
  // printf("not found an i oop\n");
  return front; //if reached end of list, just return pointer to original front
}
