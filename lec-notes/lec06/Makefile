CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex wc.tex devour.tex
	latex lec.tex

wc.tex: wc.c
	c2latex wc.c wc.tex

wc:	wc.o
	$(CC) wc.o -o wc

devour.tex: devour.c
	c2latex devour.c devour.tex

lec.ps: lec.dvi
	dvips-rok lec.dvi


print: lec.ps
	psprint lec.ps
