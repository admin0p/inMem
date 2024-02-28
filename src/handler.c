#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"set.h"
#include"handler.h"

void input_handler(int key_index, char * key, char * value){

    switch (key_index){
        
        case 0:
            printf("Exiting ....\n");
            exit(1);
            break;

        case 1:
            get_key(key);
            break;

        case 2:
            set_key(key, value);
            break;

        default:
            printf("Command not found\n");
            break;
    }

}