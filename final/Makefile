
dan.dvi: dan.tex append.tex dumbappend.tex
	latex dan.tex

dan.ps: dan.dvi
	dvips-rok dan.dvi

print: dan.ps
	psprint dan.ps

rand.tex: rand.c
	c2latex rand.c > rand.tex

append.tex: append.c
	c2latex append.c > append.tex

dumbappend.tex: dumbappend.c
	c2latex dumbappend.c > dumbappend.tex
