
lec.ps: lec.dvi
	dvips-rok lec.dvi

lec.dvi: lec.tex square.tex
	latex lec.tex

square.tex: square.c
	c2latex square.c square.tex

print: lec.ps
	psprint lec.ps
