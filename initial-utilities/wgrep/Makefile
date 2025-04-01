# Compiler
CC = gcc
CFLAGS = -Wall -Werror

wgrep: wgrep.c
	$(CC) $(CFLAGS) -o wgrep wgrep.c

test:
	./test-wgrep.sh

clean:
	@if [ -f "wgrep" ]; then rm -f wgrep; fi
	@if [ -d "tests-out" ]; then rm -rf tests-out; fi
