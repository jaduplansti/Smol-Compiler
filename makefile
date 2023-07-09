CC = gcc
CFLAGS = -Wall -g

g+: src/main.c src/lexer/lexer.c
	${CC} ${CFLAGS} -o $@ $^
  