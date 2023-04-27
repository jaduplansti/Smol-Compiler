#include <stdio.h>
#include <stdlib.h>
#include <string.h>

root_node *new_node() {
  return calloc(1, sizeof(root_node));
}