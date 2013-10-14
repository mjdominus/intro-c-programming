


int main(int argc, char **argv) 
{
  /* index of the name of the file we're working on now. */
  int i;		
  FILE *cur_file;

  for ( i=1;  i < argc; i++ ) {
    
    /* open a file and handle errors */
    cur_file = open_file(argv[i]);
    if (cur_file == NULL)
      continue;

    /* Get data from file, print data and handle errors*/
    spew(cur_file);
    
    /* close file and handle errors */
    /* postpone: announce that file is finished */
  }

  /* return success or failure code */
}


FILE * open_file(char *filename)
{
  FILE *file;

  file = fopen(filename, "r");

  if (file == NULL) {
    fprintf(stderr, "I couldn't open file %s!.\n", filename);
  }

  return file;
}


int /*?*/ spew(FILE *current)
{
  int c;
  
  while ((c = getc(current)) != EOF)
    putchar(c);


}
