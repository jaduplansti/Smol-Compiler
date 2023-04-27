typedef struct {
  void *node;
} root_node;

typedef struct {
  void *condition;
} conditional_node;

typedef struct expr_struct {
  
} binary_expr;
root_node *new_node();
conditional_node *new_con_node();