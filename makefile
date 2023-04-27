CC = gcc
CFLAGS = -Wall -g

g+: src/main.c 
	${CC} ${CFLAGS} -o $@ $^
  