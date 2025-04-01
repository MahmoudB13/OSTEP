# Compiler
CC = gcc
CFLAGS = -Wall -Werror

wcat: wcat.c
	$(CC) $(CFLAGS) -o wcat wcat.c

test:
	./test-wcat.sh

clean:
	@if [ -f "wcat" ]; then rm -f wcat; fi
	@if [ -d "tests-out" ]; then rm -rf tests-out; fi
