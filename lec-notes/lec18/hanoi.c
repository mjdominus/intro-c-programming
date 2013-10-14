
#include <stdio.h>
#include <stdlib.h>

void hanoi(int num_rings, int start_peg, int end_peg);
void move(int ring_num, int start, int end);

int main(int argc, char **argv)
{
  int num_rings;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s number_of_rings\n", argv[0]);
    return 1;
  }

  num_rings = atoi(argv[1]);

  hanoi(num_rings, 1, 3);

  return 0;
}

void
  hanoi(int num_rings,
	int start_peg, 
	int end_peg)
{
  int spare_peg = 6 - start_peg - end_peg;
  
  if (num_rings > 0) {
    hanoi(num_rings - 1, start_peg, spare_peg);
    move(num_rings, start_peg, end_peg);
    hanoi(num_rings - 1, spare_peg, end_peg);
  }

  return;
}


void move(int ring_num, int start, int end)
{
  printf("Move disk %d from peg %d onto peg %d.\n", 
	 ring_num, start, end);

  return;
}
