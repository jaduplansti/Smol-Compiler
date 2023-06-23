#include "lexer.h"

typedef struct {
  void *node;
} root_node;

typedef struct {
  void *condition;
} conditional_node;

typedef struct expr_struct {
  token_struct *token;
  struct expr_struct *left, *right;
} binary_expr;

root_node *new_node();
conditional_node *new_con_node(binary_expr *expr);
binary_expr *new_bin_expr(token_struct *token);
token_struct *new_token(const char *string, unsigned short type);