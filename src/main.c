#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *src;

int main(int argc, char **argv) {

  if(argc < 2) {
    fprintf(stderr,"No Source File Specified\n");
    return 1;
  }

  for(size_t argc_i = 1 argc_i < argc; argc_i++) { /* Loops Over Argc */
    for(size_t argc_c = 0; argc_c < strlen(argc[argc_i]); argc_c++) { /* Loops Over Characters In Argc */
      if(argc[argc_i][argc_c] == '-') { /* If Argc Character Is '-' */
        switch(argc[argc_i][++argc_c]) {
          case 's':
            /* Insert Code Here */
          break;

          case 'o':
            /* Insert Code Here */
          break;

          default:
            /* Insert Error Handling Here */
          break;
        }
      }
    }
  }


  if(src == NULL) {
    fprintf(stderr,"./g+: %s cannot be read or opened\n",argv[1]);
    return -1;
  }
  
}