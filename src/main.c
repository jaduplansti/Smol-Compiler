#include <stdio.h>
#include <stdlib.h>

FILE *src;
FILE *dst;

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stdout, "./smolc: no source file specified\n");
        return -1;
    }

    src = fopen(argv[1], "r");
    if(src == NULL) {
        fprintf(stderr, "./smolc: file %s cannot be read\n", argv[1]);
        return -1;
    }

    dst = fopen("a.asm", "w+");
    if(dst == NULL) {
        fprintf(stderr, "./smolc: cannot create \"a.asm\"\n");
        return -1;
    }
    
    return 0;
}