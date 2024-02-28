#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"set.h"
#include"handler.h"

void input_handler(int key_index, char * key, char * value){

    switch (key_index){

        case 1:
            printf("GET command detected\n");
            get_key(key);
            break;

        case 2:
            printf("SET command detected\n");
            set_key(key, value);
            break;

        default:
            printf("Command not found\n");
            break;
    }

}