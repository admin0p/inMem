#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKE_STRUCTURE
{
    const char *token;
    int key_id;
    int argument_count;
    int options_count;
    char (*options)[10];
} token_struct;

#define TOKENS_COUNT 2

extern const token_struct KEY_SPACE[TOKENS_COUNT];

#endif // TOKEN_H