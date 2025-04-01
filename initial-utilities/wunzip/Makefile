# Compiler
CC = gcc
CFLAGS = -Wall -Werror

wunzip: wunzip.c
	$(CC) $(CFLAGS) -o wunzip wunzip.c

test:
	./test-wunzip.sh

clean:
	@if [ -f "wunzip" ]; then rm -f wunzip; fi
	@if [ -d "tests-out" ]; then rm -rf tests-out; fi
