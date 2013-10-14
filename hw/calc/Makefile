CC=gcc
CFLAGS=-g

calc.dvi: calc.tex ss.tex
	latex calc.tex

ss.tex:  ss.c
	c2latex ss.c ss.tex

calc.ps: calc.dvi
	dvips-rok calc.dvi

print: calc.ps
	psprint calc.ps
