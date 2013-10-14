CC= gcc 
CFLAGS= -Wall

lec.dvi: lec.tex primes.tex # devour.tex
	latex lec.tex

primes.tex: primes.c
	c2latex primes.c primes.tex
 
primes:	primes.o
	$(CC) primes.o -o primes
 
# devour.tex: devour.c
# 	c2latex devour.c devour.tex
# 
lec.ps: lec.dvi
	dvips-rok lec.dvi


print: lec.ps
	psprint lec.ps
