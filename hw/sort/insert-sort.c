
#include <stdio.h>
#include <string.h>

#define MAXLINES 500
#define LINELEN 80

int get_lines(FILE *, char *[], int);
void put_lines(FILE *, char *[], int);
char *get_line(FILE *);
void insertion_sort(char *[], char *[], int);
void swap_strings(char **s1, char **s2);
FILE * open_file_with_errmsg(char *, char *);
int find_smallest(char *array[], int nelems);

int main(int argc, char *argv[])
{
  int num_lines;
  char *input[MAXLINES];
  char *output[MAXLINES];
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

/*   printf("number of lines read:  %d.\n", num_lines); */

  insertion_sort(input, output, num_lines);

  put_lines(out_source, output, num_lines);

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
 Sort an array of strings with the insertion sort algorithm. 
 parameters are `input', the array of strings to sort, `output',
 a similar array into which to place the answer, and 
 `nelems', the length of that array.
 Comparision is lexicographic. 
 */
void
  insertion_sort(char *input[], char *output[], int nelems)
{
  int smallest;		/* Index of smallest uncopied element in `input' */
  int i;			

  for (i=0; i<nelems; i++) {
    smallest = find_smallest(input, nelems);
    if (smallest == -1)		/* all elements in input were NULL,
				   so we're done prematurely. This is
				   a logic error and should never
				   happen. */
      abort();

    /* otherwise, copy the smallest element from input to output */
    output[i] = input[smallest];

    /* obliterate smallest input so we don't get it next time. */
    input[smallest] = NULL;
  }

  return;
}

/* Take an array, `array' and `nelems', the number of elements in
   the array, and return the index number of the 'smallest'
   (lexicographically first) element in the array. Ignore NULL elements.
   If all elements are NULL, return -1.
   */

int
  find_smallest(char *array[], int nelems)
{
  int i, smallest_so_far;

  /* Find first non-NULL element in the array */
  for (smallest_so_far = 0; 
       smallest_so_far < nelems && array[smallest_so_far] == NULL ;
       smallest_so_far ++)
    /* nothing */ ;

  if (smallest_so_far == nelems)	/* all elements were NULL */
    return -1;

  /* Search all other elements for smallest. */
  for (i=smallest_so_far+1; i<nelems; i++)
    if (array[i] != NULL &&
	strcmp(array[smallest_so_far], array[i]) > 0)
      smallest_so_far = i;

  return smallest_so_far;
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
