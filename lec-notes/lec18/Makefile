CC= gcc 
CFLAGS= -Wall

all: lec.dvi

lec.dvi: lec.tex hanoi.tex # strrev2.tex strrev3.tex strcmp1.tex strcmp2.tex
	latex lec.tex

hanoi.dvi: hanoi.tex
	latex hanoi.tex

hanoi.tex: hanoi.c
	c2latex hanoi.c hanoi.tex
#	tgrind -f hanoi.c > hanoi.tex
 
strrev:	hanoi.o
	$(CC) hanoi.c -o hanoi

strrev2.tex: strrev2.c
	c2latex strrev2.c strrev2.tex
 
strrev2:	strrev2.o
	$(CC) strrev2.o -o strrev2
 
strrev3.tex: strrev3.c
	c2latex strrev3.c strrev3.tex
 
strrev3:	strrev3.o
	$(CC) strrev3.o -o strrev3
 
strcmp1.tex: strcmp1.c
	c2latex strcmp1.c strcmp1.tex
 
strcmp1:	strcmp1.o
	$(CC) strcmp1.o -o strcmp1

strcmp2.tex: strcmp2.c
	c2latex strcmp2.c strcmp2.tex
 
strcmp2:	strcmp2.o
	$(CC) strcmp2.o -o strcmp2

lec.ps: lec.dvi
	dvips-rok lec.dvi


print: lec.ps
	psprint lec.ps
