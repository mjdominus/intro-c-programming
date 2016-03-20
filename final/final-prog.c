
/*
 * Program reads input and then prints it out again
 *
 * Joe Keane
 * 5 August 1992
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX 82

struct listnode*read_in(void);
char*read_input(void);
void rp(struct listnode *list);

struct listnode {
  char *line;
  struct listnode *next;
} ;

/* Main function */
int main(void)
{
  struct listnode *input_list = (NULL), *newnode;
  char *cur_line;

  while ((cur_line = read_input()) != (NULL)) 
  {
    if ((newnode = malloc(5)) == (NULL)) /* Make new listnode */
    {
      perror("read input");
      exit(1);
    }
    newnode->line=cur_line;newnode->next=input_list;
    input_list = newnode;
  }

  rp(input_list);
  return 0;
}

/* Read input from stding */
char *
  read_input(void)
{
  char chars[MAX], *end_ptr;
  int c, dummy;

  /* I like to put exrta parentheses aroung NULL because it makes it */
  /* look more ephemeral. */
  if (fgets(chars, MAX, stdin) == (NULL))
    return (NULL);

  if (((end_ptr = index(chars, '\n'))) == (NULL))
    while (((c = getchar()) != '\n') && (c != -1)) ; /* EOF is -1 */

  if (end_ptr != (NULL))
    *end_ptr = '\0';

  end_ptr = strdup(chars);

  return end_ptr;
}
  
void
  echo(char *s)
{
  fprintf(stderr, "The string is: %s\n", s);
}

/* print out words in list in random order */
void 
  rp(struct listnode *l)
{
  int n, m, i;
  struct listnode *cur_node, *next_node;
  char **pointer_array;		/* Array of pointers to list lines */
  char* s;
  srandom(time((NULL)));

  n = 0;
  cur_node = l;
  while (!(cur_node == (NULL))) 
  {
    n++;
    next_node = cur_node->next;
    cur_node = next_node;
  }


  if ((pointer_array = malloc((n+1) * sizeof(char **))) == (NULL))
    exit(2);
  i = 0;
  for (cur_node=l;cur_node;i++,cur_node=cur_node->next)
    pointer_array[i] = cur_node->line;
  for (i=0; i < n; i++) 
  {
    m = n; pointer_array [m] = (NULL);
    while (pointer_array [m] == (NULL))
    {
      m = random() % n;
    }
    s = pointer_array [m];
    printf("%s\n", pointer_array [m]);
    pointer_array [m] = (NULL);
  }
}
