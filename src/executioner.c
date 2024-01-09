#include "../includes/executioner.h"
#include "../includes/util.h"
#include "../includes/token.h"
#include <stdio.h>

int hash_function(char *str);

void query_executioner(int key_id, int argument_count, char (*argument)[20])
{
    switch (key_id)
    {
    case 1:
        printf("GET\n");
        break;
    case 2:
        printf("SET\n");
        int key_hash = hash_function(argument[0]);
        printf("key  hash - %d", key_hash);
        break;
    default:
        printf("Invalid Command\n");
        break;
    }
}

int hash_function(char *str) {
    unsigned int hash = 5381; // seed value (unsigned to handle larger values)
    int c;
    for (int i = 0; str[i] != NULL_TERMINATOR; i++) {
        c = str[i];
        
        hash = ((hash << 5) + hash)  + c;
    }

    return hash % 1024 ; // Use %u for printing unsigned integers
}
