# Compiler
CC = gcc
CFLAGS = -Wall -Werror

wzip: wzip.c
	$(CC) $(CFLAGS) -o wzip wzip.c

test:
	./test-wzip.sh

clean:
	@if [ -f "wzip" ]; then rm -f wzip; fi
	@if [ -d "tests-out" ]; then rm -rf tests-out; fi
