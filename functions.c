#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Should take a pointer to a node struct and print out all of the data in the list
void print_list(struct node * n) {
  while (n != NULL) {
    printf("%d\n", n->i);
    n = n->next;
  }
  if (n == NULL) {
    printf("%s\n", "[ ]");
  }
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
  struct node * beg = n;
  while (n!=NULL) {
    free(n);
    n = NULL;
    n = n->next;
  }
  return beg;
}

/**Remove the node containing data from the list pointed to by front.
If data is not in the list, nothing is changed.
Returns a pointer to the beginning of the list.**/
struct node * remove_node(struct node *front, int data) {
  struct node * current_node = front;
  struct node * previous_node;

  if (current_node!=NULL) { //if it hasn't reached the end of the list
    if (current_node->i == data) {
      if (current_node != front) { //if it's not the first node
        previous_node->next = current_node->next; //the last node gets the next node of this node
        return front;
      }
      front = front->next; //if it is the first node, the first node becomes the node after the first node
      return front;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
  return front; //if reached end of list, just return pointer to original front 
}
