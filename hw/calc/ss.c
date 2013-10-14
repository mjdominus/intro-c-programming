
#define MAXDEPTH 100		/* Stack can contain up to 100 integers */

int stack[MAXDEPTH];
int stackpointer = 0;		/* Index of next empty stack element */

int pop(void)
{
  if (stackpointer == 0) {	/* Stack is empty */
    fprintf(stderr, "The stack is empty!\n");
    exit(1);
  }

  return stack[--stackpointer];
}

void push(int val)
{
  if (stackpointer > MAXDEPTH) {	/* Stack is full */
    fprintf(stderr, "Stack overflow!\n");
    exit(1);
  }

  stack[stackpointer++] = val;
}
