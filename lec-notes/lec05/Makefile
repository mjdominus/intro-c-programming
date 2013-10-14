CC= gcc 
CFLAGS= -Wall

lec.ps: lec.dvi
	dvips-rok lec.dvi

lec.dvi: lec.tex quad.tex
	latex lec.tex

quad.tex: quad.c
	c2latex quad.c quad.tex

print: lec.ps
	psprint lec.ps

quad: quad.o
	$(CC) quad.o -o quad -lm
