CC=gcc
CFLAGS=-I.

mycp: mycopy.o
	$(CC) -o mycp mycopy.o 