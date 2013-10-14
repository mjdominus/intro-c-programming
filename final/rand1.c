
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_LINELENGTH 80

struct listnode *  get_lines(void);
char *  get_line(void);
void   print_list_in_random_order(struct listnode *list);


/*
Read lines from standar dinput, save, and print out lines in random
order.  Each input line is printed exactly once.
*/

struct listnode {
  char *line;
  struct listnode *next;
} ;

int main(void)
{
  print_list_in_random_order(get_lines());

  return 0;
}

struct listnode *
  get_lines(void)
{
  struct listnode *input_list = NULL, *newnode;
  char *cur_line;

  while ((cur_line = get_line()) != NULL) {
    if ((newnode = malloc(sizeof(struct listnode))) == NULL) {
      perror("read input");
      exit(1);
    }
    newnode->line = cur_line;
    newnode->next = input_list;
    input_list = newnode;
  }

  return input_list;
}

char *
  get_line(void)
{
  char inbuf[MAX_LINELENGTH+2], *end_ptr;
  int c;

  if (fgets(inbuf, MAX_LINELENGTH+2, stdin) == NULL)
    return NULL;

  if ((end_ptr = index(inbuf, '\n')) == NULL) 
    while ((c = getchar()) != '\n' && c != EOF)
      /* nothing */ ;
  else
    *end_ptr = '\0';		/* destroy newline char. */

  return strdup(inbuf);
}
  

void 
  print_list_in_random_order(struct listnode *list)
{
  int num_lines, random_num;
  struct listnode *cur_node;
  char **pointer_array;		/* Array of pointers to list lines */
  int i;

  srandom(time(NULL));

  /* count number of lines in list */
  for (num_lines = 0, cur_node = list;
       cur_node != NULL;
       num_lines++, cur_node = cur_node->next)
    /* nothing */ ;
  
  if ((pointer_array = malloc(num_lines * sizeof(char **))) == NULL)
    exit(2);

  for (i=0, cur_node = list;
       cur_node;
       i++, cur_node = cur_node->next)
    pointer_array[i] = cur_node->line;

  for (i=0; i < num_lines; i++) {
    do {
      random_num = random() % num_lines;
    } while (pointer_array[random_num] == NULL);
    printf("%s\n", pointer_array[random_num]);
    pointer_array[random_num] = NULL;
  }

  return ;
}

  
