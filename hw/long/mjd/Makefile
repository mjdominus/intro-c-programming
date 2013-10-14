
CC= gcc
CFLAGS= -Wall -g
OBJS= main.o add.o util.o subtract.o compare.o print.o
SRCS= main.c add.c util.c subtract.c compare.c print.c

lila: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o lila

main.o: main.c
add.o: add.c lila.h
util.o: util.c lila.h
subtract.o: subtract.c lila.h
compare.o: compare.c lila.h
print.o: print.c lila.h
lila.h: proto.h sysproto.h

proto.h: $(SRCS)
	cextract $(SRCS) > proto.h	
