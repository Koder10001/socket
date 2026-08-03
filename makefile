CC = gcc
CFLAGS = 
RM = rm -f

all: socket

socket: main.o ip.o
	$(CC) $(CFLAGS) -o socket main.o ip.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

ip.o: ip.c 
	$(CC) $(CFLAGS) -c ip.c

clean:
	$(RM) *.o socket