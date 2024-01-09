#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct SET
{
    char key[100];
    char value[100];
    struct SET *colliding_key;
} SET;

typedef struct KEY_SPACE
{
    int total_keys;
    SET *set_key_space[1024];
} KEY_SPACE;

int hash(char *key)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % 1024;
}

int main()
{

    int option = 4;

    KEY_SPACE *key_space = (KEY_SPACE *)malloc(sizeof(KEY_SPACE));
    
    printf("Please enter the option:\n");
    printf("1 -> create a SET\n");
    printf("2 -> get value of a key\n");
    printf("0 -> exit\n");



    while (option != 0)
    {
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            /* code */
            printf("Please enter the key:\n");
            char key[100];
            scanf("%s", key);
            printf("Please enter the value:\n");
            char value[100];
            scanf("%s", value);
            // create a set
            SET *new_set = (SET *)malloc(sizeof(SET));
            strcpy(new_set->key, key);
            strcpy(new_set->value, value);
            new_set->colliding_key = NULL;
            // hash the key
            int key_hash = hash(key);
            // check if the key already exists
            if(key_space->set_key_space[key_hash] == NULL){
                key_space->set_key_space[key_hash] = new_set;
            }else {
                SET *temp = key_space->set_key_space[key_hash];
                while(temp->colliding_key != NULL){
                    temp = temp->colliding_key;
                }
                temp->colliding_key = new_set;
                free (temp);
            }
            key_space->total_keys++;

            break;
        case 2:
            /* code */
            // get a value of a key
            printf("Please enter the key:\n");
            char get_key[100];
            scanf("%s", get_key);
            // hash the key
            int get_key_hash = hash(get_key);
            // check if the key already exists
            if(key_space->set_key_space[get_key_hash] == NULL){
                printf("Key does not exist\n");
            }else if(key_space->set_key_space[get_key_hash]->colliding_key == NULL){
                printf("Value of the key is: %s\n", key_space->set_key_space[get_key_hash]->value);
            } else {
                for(SET * i = key_space->set_key_space[get_key_hash]; i != NULL; i = i->colliding_key){
                    if(strcmp(i->key, get_key) == 0){
                        printf("Value of the key is: %s\n", i->value);
                        break;
                    }
                }
            }
            break;
        case 0:
            exit(0);
            return 1;
        default:
            break;
        }
    }

    return 0;
}