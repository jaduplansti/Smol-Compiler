#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"

token_t *new_token() {
    token_t *token = calloc(1, sizeof(token_t));
    token->type = type_none;
    return token;
}