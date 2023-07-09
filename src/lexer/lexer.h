typedef enum { type_none, type_ident, type_int, type_key } type_t; /* token types */

typedef struct { /* token structure */
    char *str;
    type_t type;
} token_t;

token_t *new_token();
token_t *get_token();
char *get_str();
type_t check_type(char *str);