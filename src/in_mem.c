#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include"includes/controller.h"
#include"includes/handler.h"

#include"includes/inMem.h"

/**
 * This is the main entry point of the application
 * This runs a loop to process commands form user 
 * upon encountering the exit command, the process will exit gracefully
 * max size of the command is 1024*28 bytes -> 28kb -> allocated on the stack
 * change the function name and add it to server
*/
int in_meme_entry (char * query) {

    printf("inMem=>"); // prompt
    input_controller(query);
    
    return 0;    
}