#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

token_struct *new_token() {
    token_struct *token = calloc(1, sizeof(token_struct));

    if(token == NULL) {
        fprintf(stderr,"Failed To Allocate Token!\n");
        return NULL;
    }
    
    return token;
}

token_struct *next_token(FILE *src) {
    size_t len; /* Length Of String*/
    fpos_t pos = ftell(src); /* File Position */

    size_t i = 0; /* Index */ 

    for(char ch = fgetc(src); ch != EOF || ch != ' '; ch = fgetc(src)) { /* Increments Len Until Eof Or Space */
        len++;
    }

    token_struct *token = new_token(); /* Makes A New Token */
    token->string = calloc(len, sizeof(char)); /* Allocates Memory For The String */

    fseek(src, pos, SEEK_SET); /* Seeks To Old Position Saved At Pos*/

    if(token->string == NULL) {
        fprintf(stderr,"Failed To Allocate String!\n");
        return NULL;
    }

    for(char ch = fgetc(src); ch != EOF || ch != ' '; ch = fgetc(src)) { /* I Died Inside*/
        token->string[i++] = ch;
    }

    return token;
}