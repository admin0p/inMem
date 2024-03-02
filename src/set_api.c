#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "includes/set.h"

typedef struct SET_KEY_SCHEMA {
    char key[KEY_LIMIT];
    char value[VALUE_LIMIT];
    struct SET_KEY_SCHEMA * colliding_key;
} SET_SCHEMA;

typedef struct SET_KEY_SPACE {
    int key_count;
    SET_SCHEMA * keys[KEY_SPACE_LIMIT];

} SET_KEY_SPACE;

static SET_KEY_SPACE * key_space_ptr = NULL;

//hashing function 

int hash (char * key) {
    int hash = 5381;
    int c;
    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % 1024;
}

// api to set key 

int set_key (char * key, char * value) {
        
    SET_SCHEMA * new_set = (SET_SCHEMA *) malloc(sizeof(SET_SCHEMA));
    strcpy(new_set->key, key);
    strcpy(new_set->value, value);
    new_set->colliding_key = NULL;
    int hash_index = hash(key);
    
    if(key_space_ptr == NULL){
        key_space_ptr = (SET_KEY_SPACE *) calloc(1,sizeof(SET_KEY_SPACE));
        key_space_ptr->keys[hash_index] = new_set;
        return 1;
    }

    if(key_space_ptr->keys[hash_index] == NULL) {
        key_space_ptr->keys[hash_index] = new_set;
        key_space_ptr->key_count++;
    }
    
    SET_SCHEMA * existing_key = key_space_ptr->keys[hash_index];
    for(SET_SCHEMA * iterator = existing_key; iterator != NULL; iterator = iterator->colliding_key){
        if(iterator->colliding_key == NULL){
            iterator->colliding_key = new_set;
            key_space_ptr->key_count++;
            return 1;
        }
    }
    
    return 0;

}

int get_key (char * key){

    int hash_index = hash(key);
    SET_SCHEMA * key_at_index = key_space_ptr->keys[hash_index];
    if(key_at_index == NULL){
        printf("Could not find the key!!");
        return 0;
    }

    if(strcmp(key_at_index->key, key) == 0){
        printf("key => %s \n", key);
        printf("value => %s\n", key_at_index->value);
        return 1;
    }

    for(SET_SCHEMA * iterator = key_at_index; iterator != NULL; iterator = iterator->colliding_key){
        if(strcmp(iterator->key, key) == 0){
            printf("key => %s \n", key);
            printf("value => %s \n", iterator->value);
            return 1;
        }
    }

    printf("Could not find the key!!");
    return 0;
}
