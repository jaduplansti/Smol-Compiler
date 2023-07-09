typedef enum {type_none, type_ident, type_int, type_if, type_while, type_for} type_t; /* token types */

typedef struct { /* token structure */
    char *str;
    type_t type;
} token_t;

token_t *new_token();
token_t *get_token();
