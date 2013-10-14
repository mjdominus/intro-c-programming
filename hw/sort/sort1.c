
#include <stdio.h>
#include <string.h>

#define MAXLINES 3
#define LINELEN 7

int get_lines(FILE *, char *[], int);
char *get_line(FILE *);

int main(int argc, char *argv[])
{
  int num_lines, i;
  char *input[MAXLINES];
  FILE *in_source = stdin, *out_source = stdout;

  

  num_lines = get_lines(in_source, input, MAXLINES);
  if (num_lines == -1)		/* input failed */
    return 1;

  printf("number of lines read:  %d.\n", num_lines);
  for (i=0; i< num_lines; i++)
    printf("%d: .%s.\n", i, input[i]);

  return 0;
}


/*
 * Read input lines into the array
 * `inputarray', from data source `in_source', stopping 
 * after `arraylen' lines have been read, or upon EOF, whichever
 * comes first.
 * Return number of lines actually read if successful, -1 on failure.
 */
int
  get_lines(FILE *in_source, char *inputarray[], int arraylen)
{
  int num_read = 0;		/* # of lines read so far */
  
  for (num_read = 0; num_read < arraylen; num_read ++ ) {
    inputarray[num_read] = get_line(in_source);
    /* `get_line() returned NULL.  That could be an end-of-file
       indication, which is normal, or it could indicate an error.*/
    if (inputarray[num_read] == NULL) {
      if (ferror(in_source)) {
	perror("line read");
	return -1;
      } else  {
	return num_read;
      }
    }
    printf("Line read: .%s.\n", inputarray[num_read]);
  }

  /* If we're here, we read `arraylen' lines correctly. */

  return arraylen;
}

/*
 * read a line from the input stream `in_source', LINELEN characters ar most,
 * or to a newline character, whichever comes first.  
 * Copy the line to permanent storage and return a pointer to that
 * storage.  Truncate input lines to LINELEN characters if necessary.
 * 
 * Return NULL string on end-of-file.
 */
char *
  get_line(FILE *in_source)
{
  int c; 
  int i = 0;			/* # of characters read so far */
  char temp_line[LINELEN+1];	/* Temporary array to hold input */

  while((c = getc(in_source)) != '\n' && c != EOF && i < LINELEN )
    temp_line[i++] = c;

  temp_line[i] = '\0';		/* Null-terminate input line */

  /* There were three ways out of the loop: We might be out of space in
   the buffer (i == LINELEN), out of input (c == EOF), or reached end of
   line (c == '\n').  If we stopped because we're out of space, and
   there's input remaining, we have to eat it up to truncate the line.
   If we hit EOF, we might have read some string data before that, and
   we need to return it as usual.  On the other hand, if we hit EOF
   right away, so that there's nothing in the buffer, we can signal EOF
   to our caller by returning NULL. */

  if (c == EOF && i == 0) {	/* No data at all */
    return NULL;
  } else if (c != EOF && c != '\n') {
    /* We  ran out of space before we reached end of line, so gobble up 
     * input to end of line, thus truncating the input */ 
    while ((c = getc(in_source)) != '\n' && c != EOF)
      /* Gobble gobble */ ; 
  }

  return strdup(temp_line);
}

  
