#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_TERMINATOR '\0'

typedef struct KEY_STORE
{

    char *key;
    char *value;
    struct KEY_STORE *next_colliding_key;

} KEY_STORE;

typedef struct SETS_KEY_SPACE
{

    KEY_STORE keys_space[1024];
    int key_count;

} KEY_SPACE;


int hash_function(char *str)
{
    unsigned int hash = 5381; // seed value (unsigned to handle larger values)
    int c;
    for (int i = 0; str[i] != NULL_TERMINATOR; i++)
    {
        c = str[i];

        hash = ((hash << 5) + hash) + c;
    }

    return hash % 1024; // Use %u for printing unsigned integers
}


int main()
{
    int input;
    int quit_flag = 0;

    // initialize memory 
    KEY_SPACE *key_space = (KEY_SPACE *)malloc(sizeof(KEY_SPACE));
    key_space->key_count = 0;


    char  user_key [10] = "";
    char  user_value [10] = "";

    printf("Enter your option : \n");
    printf("1. GET\n");
    printf("2. SET\n");
    printf("3. QUIT\n");

    while (quit_flag == 0)
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("GET\n");
            printf("enter the key\n");
            scanf("%s", user_key);
            printf("entered user key %s \n", user_key);
            int key_hash_index_get = hash_function(user_key);
            if(key_space->keys_space[key_hash_index_get].key == NULL){
                printf("Key not found\n");
            }else{
                printf("Key found\n");
                printf("Key : %s\n", key_space->keys_space[key_hash_index_get].key);
                printf("Value : %s\n", key_space->keys_space[key_hash_index_get].value);
            }
            break;
        case 2:
            printf("enter the key\n");
            scanf("%s", user_key);
            printf("enter the value\n");
            scanf("%s", user_value);
            
            int key_hash_index_set = hash_function(user_key);
            if(key_space->keys_space[key_hash_index_set].key == NULL){
                KEY_STORE *new_key_store = (KEY_STORE *)malloc(sizeof(KEY_STORE));
                new_key_store->key = user_key;
                new_key_store->value = user_value;
                new_key_store->next_colliding_key = NULL;

                key_space->keys_space[key_hash_index_set] = *new_key_store;
                key_space->key_count++;
            }

            break;
        case 3:
            printf("QUIT\n");
            quit_flag = 1;
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}