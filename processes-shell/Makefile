# Compiler
CC = gcc
CFLAGS = -Wall -Werror

wish: wish.c
	$(CC) $(CFLAGS) -o wish wish.c

test:
	./test-wish.sh

clean:
	@if [ -f "wish" ]; then rm -f wish; fi
	@if [ -d "tests-out" ]; then rm -rf tests-out; fi

