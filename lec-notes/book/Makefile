
CSOURCE= count.c  jeano.c  quad.c    square.c  strrev.c  swap1.c    type.c  \
	 devour.c    rev.c     strcmp1.c strrev2.c swap2.c    type2.c \
	 hanoi.c  primes.c reverse.c strcmp2.c strrev3.c  wc.c    

CTEX=    count.tex jeano.tex quad.tex square.tex strrev.tex swap1.tex \
	 type.tex devour.tex  rev.tex strcmp1.tex strrev2.tex \
	 swap2.tex type2.tex hanoi.tex primes.tex reverse.tex	 \
	 strcmp2.tex strrev3.tex  wc.tex

BOOKTEX= lec02.tex lec06.tex lec10.tex lec14.tex lec18.tex \
	 lec03.tex lec07.tex lec11.tex lec15.tex lec19.tex \
	 lec04.tex lec08.tex lec12.tex lec16.tex lec20.tex \
	 lec05.tex lec09.tex lec13.tex lec17.tex


book.dvi: $(CTEX) $(BOOKTEX)  book.tex macros.tex
	latex book.tex

book.ps: book.dvi
	dvips-rok book.dvi

print:	book.ps
	psprint -h -Plinc2 book.ps

count.tex:	count.c
	tgrind -f count.c > count.tex

jeano.tex:	jeano.c
	c2latex jeano.c jeano.tex 

quad.tex:	quad.c
#	c2latex quad.c quad.tex 
	tgrind -f quad.c > quad.tex
square.tex:	square.c
	c2latex square.c square.tex

strrev.tex:	strrev.c
	c2latex strrev.c strrev.tex 

swap1.tex:	swap1.c
	c2latex swap1.c swap1.tex 

type.tex:	type.c
	c2latex type.c type.tex 

devour.tex:	devour.c
	c2latex devour.c devour.tex 

rev.tex:	rev.c
	c2latex rev.c rev.tex 

strcmp1.tex:	strcmp1.c
	c2latex strcmp1.c strcmp1.tex 

strrev2.tex:	strrev2.c
	c2latex strrev2.c strrev2.tex 

swap2.tex:	swap2.c
	c2latex swap2.c swap2.tex 

type2.tex:	type2.c
	c2latex type2.c type2.tex 

hanoi.tex:	hanoi.c
	c2latex hanoi.c hanoi.tex 

primes.tex:	primes.c
	c2latex primes.c primes.tex 

reverse.tex:	reverse.c
	tgrind -f reverse.c > reverse.tex

strcmp2.tex:	strcmp2.c
	c2latex strcmp2.c strcmp2.tex 

strrev3.tex:	strrev3.c
	c2latex strrev3.c strrev3.tex 

wc.tex:		wc.c
	c2latex wc.c wc.tex 
