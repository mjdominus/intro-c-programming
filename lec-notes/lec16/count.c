
/* Program to read words from standard input, count number of 
   occurrences of each word, and write report onto standard output.
   
   A `word' is a sequence of non-whitespace characters.  Words therefore
   are separated by whitespace.

   28 July 1992  Mark-Jason Dominus (MJD) mjd@saul.cis.upenn.edu

   Copyright 1992 Mark-Jason Dominus and the Trustees of the University
   of Pennsylvania. All rights reserved.
*/

  
#include <stdio.h>
#include <ctype.h>		/* For isspace() */
#include <string.h>
#include <malloc.h>

#define MAXWORDLEN 80		/* We fail on words longer than
				   80 characters */

char * getword(void);
struct wordcount_node * count(char *word, struct wordcount_node *list);
struct wordcount_node * create_new_node(void);

struct wordcount_node {
  char *word;
  int count;			/* number of occurrences of this word */
  struct wordcount_node *next;	/* pointer to next node in list */
} ;

int 
  main(void)
{
  char *newword;
  struct wordcount_node *list;	/* Pointer to list of words seen so far */
  struct wordcount_node *cur;


  list = NULL;			/* Empty list */

  /* Read in words and count them */
  while ((newword = getword()) != NULL) {
    list = count(newword, list);
    free(newword);		/* `count' made a copy of `newword', so
				   we can throw `newword' away. */
  }

  /* Print out accumulated information */
  for (cur = list; cur != NULL; cur = cur->next)
    printf("%s %d\n", cur->word, cur->count);

  return 0;
}

/*
  search for `word' in `list'.  
  If it's there, increment the count associated with it.
  Otherwise, create a new node, and attach it to the front of the list.
  In either case, return a pointer to the head of the list when done.

  Note that this works correctly if `list' is NULL. */

struct wordcount_node *
  count(char *word, struct wordcount_node *list)
{
  struct wordcount_node *cur;
  struct wordcount_node *newnode;

  for (cur = list; cur != NULL; cur = cur->next)
    if (strcmp(word, cur->word) == 0) {
      cur->count++;
      return list;
    }

  /* If we're here, we didn't find the word. */

  if ((newnode = create_new_node()) == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }

  /* Attach new node to rest of list */
  newnode->next = list;
  
  /* We don't know if our caller is going to reuse or overwrite
     the memory that contains `word', so we'd better copy it if we want
     to keep it around. */
  newnode->word = strdup(word);
  
  newnode->count = 1;

  return newnode;
}
  
/* Create a new list node and return a pointer to it. 
   Return NULL if out of memory or on some other failure. 
   */
struct wordcount_node *
  create_new_node(void)
{
  return (struct wordcount_node *) malloc(sizeof(struct wordcount_node));
}


/* Read a word from standard input; return NULL on EOF. 
   Has poor behavior on words longer than MAXWORDLEN characters. 
   */
char *
  getword(void)
{
  char buf[MAXWORDLEN];
  int i=0, c;

  /* Eat up white space that precedes a word, if any. */
  while ( isspace(c = getchar()) && c != EOF  )
    /* nothing */ ;

  if (c != EOF) ungetc(c,stdin);

  /* Read word */
  while ( !isspace(c = getchar()) && c != EOF  )
    buf[i++] = c;

  buf[i] = '\0';

  if (i == 0) return NULL;	/* We hit EOF without reading anything */
  else  return strdup(buf);
}
