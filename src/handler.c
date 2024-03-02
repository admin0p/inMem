#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"includes/set.h"
#include"includes/handler.h"

void input_handler(int key_index, input_skeleton * input){

    switch (key_index){
        
        case 0:
            printf("Exiting ....\n");
            exit(1);
            break;

        case 1:
            get_key(input->arguments[0]);
            break;

        case 2:
            set_key(input->arguments[0], input->arguments[1]);
            break;

        default:
            printf("Command not found\n");
            break;
    }

}