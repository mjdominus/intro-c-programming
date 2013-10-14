
struct listnode {
  char *data;
  struct listnode *next;
} ;

struct listnode *make_new_listnode(void);

int append(char *new_data, struct listnode *list_head)
{
  struct listnode *tail, *newnode;
  
  newnode = make_new_listnode();
  if (newnode == NULL) return -1;

  for (tail=list_head; tail->next != NULL; tail=tail->next) 
    /* nothing */ ;

  tail->next = newnode;
  newnode->next = NULL;
  newnode->data = new_data;

  return 0;
}
