#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "includes/set.h"

/**
 * This file is the main "SET" engine to handle key value pair structures
 * This manages the memory allocation and deallocation <To be added on key deletion>
 * This stores the SET structure and SET key space
 * SET key space is just a hash map that points to the location of the key structure
*/

/**
 * @brief
 * This is the main SET structure that stores the key value
 * The limits for key size and value size are defined in includes/set.h
 * key: the key
 * value: the value associated to the key
 * colliding_key: on collision of hash indexes for a key the former key points to the location of the later key
 * sort of like linked list
 * example:
 * index->      0           1              2
 *        [ {SET struct}  {SET struct}  {SET struct} ]
 *              |
 *     {colliding SET struct} 
 *              |
 *     {colliding SET struct} 
*/
typedef struct SET_KEY_SCHEMA {
    char key[KEY_LIMIT];
    char value[VALUE_LIMIT];
    struct SET_KEY_SCHEMA * colliding_key;
} SET_SCHEMA;

/**
 * @brief
 * This is the SET key space
 * Keeps track of the total keys and assigns keys to their hashed index
*/
typedef struct SET_KEY_SPACE {
    int key_count;
    SET_SCHEMA * keys[KEY_SPACE_LIMIT];

} SET_KEY_SPACE;

static SET_KEY_SPACE * key_space_ptr = NULL;

/**
 * Function to get hashed index to the key
*/
int hash (char * key) {
    int hash = 5381;
    int c;
    while (c = *key++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % KEY_SPACE_LIMIT;
}

/**
 * @brief
 * API function to create a key_value set in memory <HEAP>
 * This creates a SET structure in memory <HEAP> and also populate the SET key_space 
*/
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
        return 1;
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

/**
 * @brief
 * This function retrieves the value associated to a key 
*/
void get_key (char * key){

    int hash_index = hash(key);
    SET_SCHEMA * key_at_index = key_space_ptr->keys[hash_index];
    if(key_at_index == NULL){
        printf("Could not find the key!!");
        return;
    }

    if(strcmp(key_at_index->key, key) == 0){
        printf("key: %s \n", key);
        printf("value: %s\n", key_at_index->value);
        return;
    }

    for(SET_SCHEMA * iterator = key_at_index; iterator != NULL; iterator = iterator->colliding_key){
        if(strcmp(iterator->key, key) == 0){
            printf("key: %s \n", key);
            printf("value: %s \n", iterator->value);
            return;
        }
    }

    printf("Could not find the key!! \n");
    return;
}

/**
 * @brief
 * This function gets the info of the key
 * key
 * at which heap address is the key stored of the program's address space
 * number of colliding hops for the key
 * the hash number for the key 
*/
void get_key_info (char * key) {

    int hash_index = hash(key);
    int colliding_hash_hops = 0;
    SET_SCHEMA * key_at_index = key_space_ptr->keys[hash_index];

    if(strcmp(key, key_at_index->key) == 0){

        printf("key: %s \n", key);
        printf("at_address: %p \n", key_at_index);
        printf("colliding_hash_hops %d \n", colliding_hash_hops);
        printf("key_hash: %d\n", hash_index);

        return;
    }

    for (SET_SCHEMA * ptr = key_at_index; ptr != NULL; ptr = ptr->colliding_key){
        colliding_hash_hops ++;
        if(strcmp(key, ptr->key) == 0){
             printf("key: %s \n", key);
            printf("at_address: %p \n", key_at_index);
            printf("colliding_hash_hops %d \n", colliding_hash_hops);
            printf("key_hash: %d\n", hash_index);
            return;
        }
    }

    printf("Could not find the key!! \n");

}
