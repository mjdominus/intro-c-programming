
struct node {
	char *data;
	struct node * next;
} ;


int
  rand_print(struct node *head_node_p)
{
  int length, i, j;
  struct node p;		/* Temporary structure */
  char **data_table;		/* Array of strings in list */

  for (p = *head_node_p; p.next!=NULL; p=*p.next) 
    length++;

  data_table = malloc(length * sizeof(char **));
  if (data_table == NULL)
    return -1;

  for (p=*head_node_p,i=0;p.next;p=*p.next,i++) 
    data_table[i] = p.data;

  for (j=0; j<length; j++) {
    while (data_table[i] == NULL)
      i = random() % length;
    printf(data_table[i]);
    data_table[i] = NULL;
  }

  return 0;
}
