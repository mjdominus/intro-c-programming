

/* One of these per list */
struct list {
  struct listnode *head;	/* Always points to first node in list */
  struct listnode *tail;	/* Always points to last node in list */
} ;

/* One of these per list node */
struct listnode {
  char *data;
  struct listnode *next;
} ;				/* List nodes */

