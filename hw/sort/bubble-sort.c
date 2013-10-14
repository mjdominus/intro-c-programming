
#include <stdio.h>
#include <string.h>

#define MAXLINES 500
#define LINELEN 80

int get_lines(FILE *, char *[], int);
void put_lines(FILE *, char *[], int);
char *get_line(FILE *);
void bubble_sort(char *[], int);
void swap_strings(char **s1, char **s2);
FILE * open_file_with_errmsg(char *, char *);

int main(int argc, char *argv[])
{
  int num_lines;
  char *input[MAXLINES];
  FILE *in_source = stdin, *out_source = stdout;

  switch(argc) {
  case 3:
    out_source = open_file_with_errmsg(argv[2], "w");
    if (out_source == NULL)
      return 2;
    /* Fall through */
  case 2:
    in_source = open_file_with_errmsg(argv[1], "r");
    if (in_source == NULL)
      return 2;
    /* Fall through */
  case 1:
    break;
  default:			/* More then 2 args */
    fprintf(stderr, "Usage:\t %s [ infile [ outfile ] ] \n",
	    argv[0]);
    return 2;
    break;
  }

  num_lines = get_lines(in_source, input, MAXLINES);
  if (num_lines == -1)		/* input failed */
    return 1;

/*   printf("number of lines read:  %d.\n", num_lines);*/

  bubble_sort(input, num_lines);

  put_lines(out_source, input, num_lines);

  return 0;
}

void
  put_lines(FILE *out_source, char *outputarray[], int arraylen)
{
  int i;

  for (i=0; i< arraylen; i++) 
    fprintf(out_source, "%d.%s.\n", i, outputarray[i]);

  return;
}

/* 
 Sort an array of strings with the bubble sort algorithm. 
 parameters are `data', the array of strings to sort, and 
 `nelems', the length of that array.
 sort in place and return.
 Comparision is lexicographic. 
 */
void
  bubble_sort(char *data[], int nelems)
{
  int cur_bubble;		/* How many times have we bubbled so far? */
  int what_pair;		/* What pair of elements are we 
				   comparing now? A pair can be denoted
				   by the index of the leftmost element;
				   this is what we store in `what_pair'. */


  for (cur_bubble = 1; cur_bubble < nelems; cur_bubble++)
    for (what_pair = 0; what_pair < nelems-cur_bubble; what_pair ++)
      if (strcmp(data[what_pair], data[what_pair+1]) > 0) 
	swap_strings(& data[what_pair], & data[what_pair+1]);

  return;
}

/* Take pointers to two strings and swap their values. */
void
  swap_strings(char **s1, char **s2)
{
  char *temp;

  temp = *s1;
  *s1 = *s2;
  *s2 = temp;

  return;
}


/*
  Read input lines into the array
  `inputarray', from data source `in_source', stopping 
  after `arraylen' lines have been read, or upon EOF, whichever
  comes first.
  Return number of lines actually read if successful, -1 on failure.
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
/*     printf("Line read: .%s.\n", inputarray[num_read]);*/
  }

  /* If we're here, we read `arraylen' lines correctly. */

  return arraylen;
}

/*
  Read a line from the input stream `in_source', LINELEN characters ar most,
  or to a newline character, whichever comes first.  
  Copy the line to permanent storage and return a pointer to that
  storage.  Truncate input lines to LINELEN characters if necessary.
  
  Return NULL string on end-of-file.
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

  

/*
 * try to open the file named `filename' for reading or writing.
 * On failure, print an error message to stderr, and
 * return NULL.  On success, return FILE * 
 * for file.  `mode' is like in fopen.
 */
FILE *
  open_file_with_errmsg(char *filename, char *mode)
{
  FILE * the_file;

  the_file = fopen(filename, mode);

  if (the_file == NULL) {
    extern int errno;
    int e;

    e = errno;
    fprintf(stderr, "Error opening file %s: ", filename);
    perror(NULL);
    return NULL;
  }

  return the_file;
}
