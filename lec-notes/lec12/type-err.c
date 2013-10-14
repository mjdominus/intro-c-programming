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
      fprintf(stderr, "Couldn't open file %s.\n", argv[i]);
      num_errors += 1;
      continue;
    }

    while ((c = getc(cur_file)) != EOF) 
      putchar(c);

    /* If we're here, we either saw end-of-file on {\tt the\_file}, */
    /* or encountered a read error.  Which was it? */

    if (ferror(cur_file)) {
      fprintf(stderr, "Read error on file %s.\n", argv[i]);
      num_errors += 1;
    }

    fclose(cur_file);
  }

  return num_errors;
}

    
      
