CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex type.tex # jeano.tex
	latex lec.tex

type.tex: type.c
	c2latex type.c type.tex
 
type:	type.o
	$(CC) type.o -o type

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
