#include <stdio.h>
#include <string.h>
#include "../includes/util.h"

// initialize the key structure in memory
#define INPUT_SIZE 200
#define TOKEN_SIZE 20
#define ARGUMENT_COUNT 10



int main()
{
    char user_input[INPUT_SIZE];
    fgets(user_input, INPUT_SIZE, stdin);

    char token[TOKEN_SIZE];
    memset(token, 0, TOKEN_SIZE);
    get_token(user_input, token, TOKEN_SIZE, " ");
    
    printf("You entered: %s\n", token);
    return SUCCESS_STATUS; // defined in util.h
}