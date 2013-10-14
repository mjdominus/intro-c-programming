
int delete(struct node *n)
{
  if (n->prev)
    n->prev->next = n->next;

  if (n->next)
    n->next->prev = n->prev;

  return free(n);
}

