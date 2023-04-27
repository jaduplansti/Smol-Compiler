#include <stdio.h>
#include <stdlib.h>
#include <string.h>

root_node *new_node() {
  return calloc(1, sizeof(root_node));
}

conditional_node *new_con_node(binary_expr *expr) {
  
}