CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex swap1.tex swap2.tex
	latex lec.tex

swap1.tex: swap1.c
	c2latex swap1.c swap1.tex
 
swap1:	swap1.o
	$(CC) swap1.o -o swap1

swap2.tex: swap2.c
	c2latex swap2.c swap2.tex
 
swap2:	swap2.o
	$(CC) swap2.o -o swap2
 
# devour.tex: devour.c
# 	c2latex devour.c devour.tex
# 
lec.ps: lec.dvi
	dvips-rok lec.dvi


print: lec.ps
	psprint lec.ps
