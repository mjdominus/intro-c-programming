#include <stdio.h>

int main(int argc, char **argv)
{
  int i;
  int c;
  FILE *cur_file;
  int num_errors = 0;

  for (i=1; i<argc; i++) {
    cur_file = fopen(argv[i], "r");
    if (cur_file == NULL) {
      printf("Couldn't open file %s.\n", argv[i]);
      num_errors += 1;
      continue;
    }

    while ((c = getc(cur_file)) != EOF) 
      putchar(c);

    fclose(cur_file);
  }

  return num_errors;
}

    
      
