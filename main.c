#include <stdio.h>
#include <stdlib.h>

FILE *src;

int main(int argc, char **argv) {
  if(argc < 2) {
    fprintf(stderr,"No Source File Specified");
    return 1;
  }
  src = fopen(argv[1], "r");
  if(src == NULL) {
    fprintf(stderr,"./g+: %s cannot be read or opened\n",argv[1]);
    return 1;
  }
  
}