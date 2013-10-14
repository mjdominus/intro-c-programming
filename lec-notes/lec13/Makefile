CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex type2.tex # jeano.tex
	latex lec.tex

type2.tex: type2.c
	c2latex type2.c type2.tex
 
type2:	type2.o
	$(CC) type2.o -o type2

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
