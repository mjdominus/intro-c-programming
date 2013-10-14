/*
Write the function `strupcase', whose argument is a string, and which
changes the lowercase letters in its argument to uppercase ones.
That means that if I do:
	char word[]="Fo-o";
	printf("%s", word);
	strupcase(word);
	printf("%s", word);
whould print `Fo-o' and then `FO-O'.  Assume `toupper()'. 

*/

void strupcase(char *s)
{
  while (*s != '\0') {
    *s = toupper(*s);
    s++;
  }
}
