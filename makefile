CC = gcc
CFLAGS = 
RM = rm -f

all: socket

socket: main.o ip.o
	$(CC) $(CFLAGS) -o socket *.c

clean:
	$(RM) *.o socket