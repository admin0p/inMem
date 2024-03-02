#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include"includes/controller.h"
#include"includes/handler.h"

/**
 * This is the main entry point of the application
 * This runs a loop to process commands form user 
 * upon encountering the exit command, the process will exit gracefully
 * max size of the command is 1024*28 bytes -> 28kb -> allocated on the stack
*/
int main () {

    int status = 1;

    while(status == 1) {
        char query[1024*28];
        printf("inMem=>"); // prompt
        fgets(query, 1024*28, stdin);
        input_controller(query);
    }
    return 0;    
}