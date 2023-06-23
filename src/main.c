#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *src;

int main(int argc, char **argv) {

  if(argc < 2) {
    fprintf(stderr,"No Arguement Specified\n");
    return -1;
  }

  FILE *src = NULL;
  FILE *dst = NULL;

  for(size_t argc_i = 1; argc_i < argc; argc_i++) { /* Loops Over Argc */
    for(size_t argv_c = 0; argv_c < strlen(argv[argc_i]); argv_c++) { /* Loops Over Characters In Argv */
      if(argv[argc_i][argv_c] == '-') { /* If Argc Character Is '-' */
        switch(argv[argc_i][++argv_c]) {
          case 's':
            if(argv[++argc_i] == NULL) {
              fprintf(stderr, "You Forgot To Include A Source File After \'-s\' \n");
              return -1;
            }

            src = fopen(argv[argc_i], "r");
            
            if(src == NULL) {
                fprintf(stderr, "File \"%s\" Does Not Exist\n", argv[argc_i]);
                return -1;
            }
            
          break;

          case 'o':
          
             if(argv[++argc_i] == NULL) {
              fprintf(stderr, "You Forgot To Include A Output File After \'-o\' \n");
              return -1;
            }

            dst = fopen(argv[argc_i], "w+");
            
            if(dst == NULL) {
                fprintf(stderr, "File \"%s\" Cannot Be Created\n", argv[argc_i]);
                return -1;
            }
            
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