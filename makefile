CC = gcc
CFLAGS = -Wall -g

smolc: src/main.c src/lexer/lexer.c
	${CC} ${CFLAGS} -o $@ $^
  