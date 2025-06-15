CC = gcc
CFLAGS = -Wall -Wextra -O2 -g

main:
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f main
