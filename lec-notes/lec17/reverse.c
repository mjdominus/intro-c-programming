
#include <stdio.h>
#include <malloc.h>

#define BOGUS_VALUE 0		/* Terminates input */

struct node {
  struct node *back;
  int number;
  struct node *forward;
} ;

int getnum(void);

/* returns pointer to new tail of list. */
struct node * store_input(int input, struct node *tail);

void print_forward(struct node *head);
void print_backward(struct node *tail);

int main (void) 
{
  int input;
  struct node *head, *tail;

  tail = head = malloc(sizeof(struct node));
  head->forward = NULL;
  head->number = BOGUS_VALUE;
  head->back = NULL;
 
  while ((input = getnum())  != BOGUS_VALUE) {
    /* store input in the list */
    tail = store_input(input,tail);
  }
  
  /* print out forwards */
  print_forward(head);
  /* print out backwards */
  print_backward(tail);
 
  return 0;
}

struct node * store_input(int input, struct node *tail)
{
  struct node *newnode; 

  newnode = malloc(sizeof(struct node));
  newnode->number = input;
  tail->forward = newnode;
  
  newnode->forward = NULL;
  newnode->back = tail;

  return newnode;
}

void print_forward(struct node *head)
{
  head = head->forward;

  while(head != NULL) {
    printf("%d\n", head->number);
    head = head->forward;
  }
}

void print_backward(struct node *tail)
{
  while(tail->number != BOGUS_VALUE) {
    printf("%d\n", tail->number);
    tail = tail->back;
  }
}

int getnum(void)
{
  int i;
   scanf("%d", &i);
  return i;
}
