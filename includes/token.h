#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKE_STRUCTURE {
    const char * token; 
    int argument_count;
    int options_count;
    char (*options)[10];
} token_struct;

#define TOKENS_COUNT 2

const token_struct TOKENS [] = {
    {"GET", 1, 0},
    {"SET", 2, 0}
};

#endif // TOKEN_H