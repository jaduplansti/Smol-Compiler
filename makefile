CC = gcc
CFLAGS = -Wall -g

main: src/main.c 
  ${CC} ${CFLAGS} -o $@ $^
  