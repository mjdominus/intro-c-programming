
int num = 0;

while ( num < 1 || num > 50 ) {
  printf("Enter an integer between 1 and 50.\n");

  if (scanf("%d", &num) < 1) {
    /* Gobble up rest of input line */
    while (getchar() != '\n')
      /* do nothing */ ;
  }
}
