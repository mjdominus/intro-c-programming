
int append(char *new_data, struct listnode *list_head)
{
  struct listnode *tail, *newnode;
  
  newnode = make_new_listnode();
  if (newnode == NULL) return -1;

  /* Your fast code from problem 1.1 goes here */

  for (p=list_head; p->next; p=p->next) 
    p->later = newnode ;	/* Update {\tt later} pointers */

  tail->next = newnode;
  newnode->next = NULL;
  newnode->data = new_data;

  return 0;
}
