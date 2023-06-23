#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

root_node *new_node() {
  return calloc(1, sizeof(root_node));
}

conditional_node *new_con_node(binary_expr *expr) {
  conditional_node *con_node = calloc(1, sizeof(conditional_node));
  if(con_node == NULL) {
    fprintf(stderr,"Failed To Allocate Node!\n");
  } 
  con_node->condition = expr;

  return con_node;
}
