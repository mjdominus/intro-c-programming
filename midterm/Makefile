CC= gcc 
CFLAGS= -Wall

key.dvi: key.tex  pow.tex strrev.tex getint.tex pow2.tex
	latex key.tex

pow.tex: pow.c
	( echo '\begin{verbatim}' ; cat pow.c ; echo '\end{verbatim}' ) \
		> pow.tex

pow2.tex: pow2.c
	( echo '\begin{verbatim}' ; cat pow2.c ; echo '\end{verbatim}' ) \
		> pow2.tex

strrev.tex: strrev.c
	( echo '\begin{verbatim}' ; cat strrev.c ; echo '\end{verbatim}' ) \
		> strrev.tex

getint.tex: getint.c
	( echo '\begin{verbatim}' ; cat getint.c ; echo '\end{verbatim}' ) \
		> getint.tex


midterm.dvi: midterm.tex confusticate.tex mean.tex hail.tex
	latex midterm.tex

confusticate.tex: confusticate.c
	( echo '\begin{verbatim}' ; cat confusticate.c ; echo '\end{verbatim}' ) \
		> confusticate.tex
 
confusticate:	confusticate.o
	$(CC) confusticate.o -o confusticate

mean.tex: mean.c
	( echo '\begin{verbatim}' ; cat mean.c ; echo '\end{verbatim}' ) \
		> mean.tex
 
mean:	mean.o
	$(CC) mean.o -o mean
 
# devour.tex: devour.c
# 	c2latex devour.c devour.tex
# 
midterm.ps: midterm.dvi
	dvips-rok midterm.dvi

key.ps: key.dvi
	dvips-rok key.dvi

print-key: key.ps
	psprint key.ps

print: midterm.ps
	psprint midterm.ps

hail.tex: hail.c
	( echo '\begin{verbatim}' ; cat hail.c ; echo '\end{verbatim}' ) \
		> hail.tex
 
hail:	hail.o
	$(CC) hail.o -o hail
