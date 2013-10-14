CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex # rev.tex jeano.tex
	latex lec.tex

rev.tex: rev.c
	c2latex rev.c rev.tex
 
rev:	rev.o
	$(CC) rev.o -o rev

jeano.tex: jeano.c
	c2latex jeano.c jeano.tex
 
jeano:	jeano.o
	$(CC) jeano.o -o jeano
 
# devour.tex: devour.c
# 	c2latex devour.c devour.tex
# 
lec.ps: lec.dvi
	dvips-rok lec.dvi


print: lec.ps
	psprint lec.ps
