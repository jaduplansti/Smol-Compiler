#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

/* TODO: add operator stack 
   add push and pop methods */
extern FILE *src;
static char keywords[][] = { /* lookup table for keywords */
    "auto", "double", "int", "struct",
    "break", "else", "long", "switch",
    "case", "enum", "register", "typedef",
    "char", "extern", "return", "union",
    "continue", "for", "signed", "void",
    "do", "if", "static", "while",
    "default", "goto", "sizeof", "volatile",
    "const", "float", "short", "unsigned"
};
const size_t KEYWORDS_SIZE = sizeof(keywords) / sizeof(*keywords); /* size of 2d array of keywords */

type_t check_type(char *str) {
    for(size_t i = 0; i < KEYWORDS_SIZE; i++) {
        if(strcmp(str, keywords[i]) == 0) return type_key;
    }

    if(isalpha(str[0])) return type_ident;
    else if(isdigit(str[0])) return type_int;
    else if(str[0] == '-' && isdigit(str[1])) return type_int;
    /* else if(str[0] == ';') */
}

char *get_str() {
    size_t pos = ftell(src); /* saves current file pointer position */
    size_t len = 0; /* length of string to be allocated */
    size_t i = 0; /* index of string */
    char *str;

    for(char ch = fgetc(src);; ch = fgetc(src)) { /* loops until EOF or '\n' is found */
        if(ch == EOF || ch == '\n') break;
        len++;   
    }

    if(fseek(src, pos, SEEK_SET) != 0) { /* checks if fseek failed */
        fprintf(stderr, "./lexer: failed to reseek file pointer\n");
        return NULL;
    }
    
    str = calloc(len, sizeof(char)); /* allocates memory for string*/
    if(str == NULL) { /* checks if memory allocation for string failed */
        fprintf(stderr, "./lexer: failed to allocate memory of %d for str\n", len);
        return NULL;
    }

    for(char ch = fgetc(src);; ch = fgetc(src)) { 
        if(ch == EOF || ch == '\n') break;
        str[i++] = ch; /* appends character to str */
    }

    str[i] = '\0' /* null terminates the string */
    return str;
}

token_t *new_token() {
    token_t *token = calloc(1, sizeof(token_t));
    token->type = type_none;
    return token;
}

token_t *get_token() {
    if(feof(src) != 0) return NULL; /* if end of file */
    char *str = get_str();
    
    /* if(str == NULL) */
    
    token_t *token = new_token();
    token->str = str;
    token->type = check_type(token->str);

    return token;
}