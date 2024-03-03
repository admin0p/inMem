#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"includes/set.h"
#include"includes/handler.h"

/**
 * @brief
 * This function just gets the index of the key calculate in controller.c and input_skeleton to process the arguments
 * Just a switch statement to handle the ops for the command
*/
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
            int ack = set_key(input->arguments[0], input->arguments[1]);
            printf("set_ack: %d \n", ack);
            break;
        
        case 3:
            get_key_info(input->arguments[0]);
            break;

        default:
            printf("Command not found\n");
            break;
    }

}