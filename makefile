CC = gcc
CFLAGS = -Wall -g

g+: src/main.c src/node.c src/lexer.c
	${CC} ${CFLAGS} -o $@ $^
  