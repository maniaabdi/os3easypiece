CC=gcc
CFLAGS=-g -Wall -I.

ODIR=obj

p1: p1.c
	$(CC) -o p1 p1.c $(CFLAG)

h1: h1.c
	$(CC) -o h1 h1.c $(CFLAG)

h2: h2.c
	$(CC) -o h2 h2.c $(CFLAG)

h3: h3.c
	$(CC) -o h3 h3.c $(CFLAG)

h4: h4.c
	$(CC) -o h4 h4.c $(CFLAG)

h5: h5.c
	$(CC) -o h5 h5.c $(CFLAG)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
