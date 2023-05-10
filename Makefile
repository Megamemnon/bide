CC=gcc
CFLAGS=-g -I.
DEPS=include/bide.h include/bidelib.h
OBJ=src/bide.c src/bidelib.c
LIBS=-lgc

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bide: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *.o *~ core 