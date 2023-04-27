CC = gcc
CFLAGS = -Wall -g

g+: src/main.c src/node.c
	${CC} ${CFLAGS} -o $@ $^
  