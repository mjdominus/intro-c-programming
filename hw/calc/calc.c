/*

Your program will implement a reverse Polish notation calculator.  The
program will read from the standard input.  Your program will compute
the values of all expressions entered.  Expressions will consist of
integers and operators.  Your program will recognize the operators {\tt
+}, {\tt -}, {\tt *}, {\tt /}, and {\tt \%}.  Furthermore, your program
will print out the most recently computed result when it sees the
operator {\tt =}.  Your program will discard the most recently computed
result when it sees the operator {\tt .}.  

Your program will not place any arbitrary limits on the complexity of
the expressions the user can evaluate.  Your program will handle error
conditions as gracefully as possible and will print appropriate error
messages if memory is exhausted or if the expression the user enters
contains an error.

1 August 1992
Mark-Jason Dominus
*/


#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

void push(int c);
int pop(void);
void print_stack(void);

struct stacknode {
  int num;
  struct stacknode *next;
} ;

int main(void)
{
  int input_num;
  int c;

  while ((c = getchar()) != EOF) {
    if (isdigit(c)) {
      ungetc(c, stdin);
      if (scanf("%d", &input_num) < 0) {
	fprintf(stderr, "Read error on number input.\n");
	return -1;
      }
      push(input_num);
    } else if (isspace(c)) {
      continue;
    } else {
      switch(c) {
	int tmp;

      case '+':
	push(pop()+pop());
	break;
      case '-':
	tmp = pop();
	push(pop() - tmp);
	break;
      case '*':
	push(pop()*pop());
	break;
      case '/':
	tmp = pop();
	push(pop() / tmp);
	break;
      case '%':
	tmp = pop();
	push(pop() % tmp);
	break;
      case '=':
	tmp = pop();
	printf("%d\n", tmp);
	push(tmp);
	break;
      case '.':
	pop();
	break;
      case '?':
	print_stack();
	break;
      default:
	fprintf(stderr, "Unrecognized operator: %c\n", c);
	break;
      }
    }
  } 

  /* We saw EOF. */

  return 0;
}


struct stacknode *stack = NULL;

int pop(void) 
{
  int topval;
  struct stacknode *second;	/* Points to next-to-top node */

  if (stack == NULL) {
    fprintf(stderr, "Stack empty; can't pop.\n");
    return 0;			/* Not a fatal error */
  }

  topval = stack->num;
  second = stack->next;
  free(stack);			/* Discard top node */
  stack = second;
  return topval;
}

void push(int newtopval)
{
  struct stacknode *newtopnode;

  if ((newtopnode = malloc(sizeof(struct stacknode))) == NULL) {
    fprintf(stderr, "Couldn't extend stack---out of memeory perhaps?\n");
    exit(2);			/* Fatal error */
  }

  newtopnode->next = stack;
  newtopnode->num = newtopval;
  stack = newtopnode;
}

void print_stack(void)
{
  struct stacknode *cur;

  for (cur = stack; cur; cur=cur->next)
    printf("%d%c", cur->num, cur->next ? ' ' : '\n' );

  return;
}
