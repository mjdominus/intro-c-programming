
#include <stdio.h>

int main(void)
{
  double total = 0.0, current = 1.0, mean;
  int input_count = 0;

  /* do...while would be better here but we hadn't done that yet. */
  while (current != 0) {	
    printf("Enter another number, or 0 to stop.\n");
    scanf("%lf", &current);
    
    if (current != 0) {
      input_count += 1;
      total += current;
    }
  }

  if (input_count > 0) {
    mean = total / input_count;
    printf("The mean of your inputs was %f.\n", mean);
  }

  return 0;
}

  
