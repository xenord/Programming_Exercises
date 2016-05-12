CC=gcc 
CFLAGS=-std=gnu89 -Wall -pedantic

eseguimi: mia_libreria.c mia_libreria_main.c
	$(CC) -o eseguimi $(CFLAGS) mia_libreria.c mia_libreria_main.c

clean:
	rm -rf eseguimi
run: eseguimi
	./eseguimi
