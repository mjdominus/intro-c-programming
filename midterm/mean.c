#include <stdio.h>
int main(void)
{
  int input_count = 0;    /* Number of inputs from user 
  float cur_input;         * most recent input 
  float total = 0;         * total of all inputs so far 
  float mean;              * arith. mean of all inputs */

  do {
    scanf("%d", &cur_input);
    total += cur_input;
    input_count++; 
  } while ( cur_input != 0);  

  mean = total / input_count;
  printf("The mean of the %d inputs is %f.\n", input_count, mean);
  return 0;
}
