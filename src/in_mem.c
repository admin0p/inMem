#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"includes/controller.h"
#include"includes/handler.h"

#include"includes/inMem.h"
#include"includes/network.h"

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

void in_mem_2 (int pipeId[2]) {

    close(pipeId[1]); // close the write end of the pipe

    while (1){
        CLIENT_REQUEST client_request;
        
        int read_status = read(pipeId[0], &client_request, sizeof(CLIENT_REQUEST));
        if(read_status <= 0) {
            break;
        }

        printf("Received message from parent: %d\n", client_request.client_fd);
        input_controller(client_request.query);

    }

}
