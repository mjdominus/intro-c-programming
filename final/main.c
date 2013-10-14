
#include <malloc.h>
#define NULL 0

struct node {
	char *data;
	struct node * next;
} ;

char *d[] = {
  "1\n", "II\n", "three\n", "quattuor\n", "cinq\n", "sies\n",
  "sieben\n", "........\n", 
  "1001\n", "A\n"
  };

int rand_print(struct node *head_node_p);

int main(void)
{
  struct node *head = NULL, *tail = NULL;
  int i;

  srandom(time(NULL));

  for (i=0; i<(sizeof(d)/sizeof(d[0])); i++) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    if (!head) head = newnode;
    if (tail) tail->next = newnode;
    newnode -> data = d[i];
    tail = newnode;
  }

  tail->next = NULL;

  return rand_print(head);
}
    
