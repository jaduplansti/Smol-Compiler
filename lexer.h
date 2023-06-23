#include <stdio.h>

typedef struct {
  char *string;
  enum {type_id, type_int} type;
} token_struct;

token_struct *new_token();
token_struct *next_token(FILE *src);