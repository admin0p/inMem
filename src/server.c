#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<pthread.h>

#include"includes/inMem.h"
#include"includes/network.h"

#define PORT 1229
#define MAX_CONNECTION_IN_LISTEN_QUEUE 5

#define BUFFER_SIZE 1028 * 4

void * handle_accepted_clients (void * args); 

int main ( ) {
    // initialize pipe
    int pipe_fds[2];
    int pipe_status = pipe(pipe_fds);
    if(pipe_status < 0){
        printf("Failed to initialize pipe -- Terminating!!");
        return -1;
    }
    // fork the process
    int fork_status = fork();
    if(fork_status == 0){
        in_mem_entry(pipe_fds);
        return 0;
    }

    // initialize socket
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock_fd < 0 ){
        printf("Failed to initialize socket -- Terminating !!");
        return -1;
    }
    
    // set socket structure to bind it to a specific port and interface
    struct sockaddr_in server_socket_address;
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_port = htons(PORT);
    server_socket_address.sin_addr.s_addr = INADDR_ANY;

    int socket_bind_status = bind(server_sock_fd, (struct sockaddr *)&server_socket_address, sizeof(server_socket_address));
    if(socket_bind_status < 0){
        printf("Failed to bind the socket to %d -- Terminating!!", PORT);
        return -1;
    }

    //listen to the socket 
    int listen_status = listen(server_sock_fd, MAX_CONNECTION_IN_LISTEN_QUEUE);
    if(listen_status < 0){
        printf("Failed to initialize listener -- Terminating!!");
        return -1;
    }
    printf("Listening on port = %d\n", PORT);
    // accept connection
    while (1) {
        pthread_t new_thread;

        struct sockaddr_in new_client;
        int client_addr_struct_size = sizeof(new_client);
        int new_client_fd = accept(server_sock_fd, (struct sockaddr *)&new_client, (socklen_t *)&client_addr_struct_size);
        if (new_client_fd < 0) {
            printf("Failed to accept the connection -- Terminating!!");
            return -1;
        }
        char client_IP[INET_ADDRSTRLEN];  
        inet_ntop(AF_INET, &(new_client.sin_addr), client_IP, INET_ADDRSTRLEN);
        printf("new client connected - %s \n", client_IP);

        REQ_H_OBJ new_req_obj;
        new_req_obj.client_fd = new_client_fd;
        new_req_obj.pipe_fds[0] = pipe_fds[0]; // read end of the pipe
        new_req_obj.pipe_fds[1] = pipe_fds[1]; // write end of the pipe

        pthread_create(&new_thread, NULL, handle_accepted_clients, (void *)&new_req_obj);
        pthread_detach(new_thread);
    }

    
    return 0;
}

/**
 * Function to handle accepted connection from clients
 * Each connection is handled in a separate thread
 * @param args : REQ_H_OBJ object
 * flow :
 *  1. read from the client
 *  2. write to the pipe
 *  Handle the query send by the user in the forked engine
*/
void * handle_accepted_clients (void * args) {
    REQ_H_OBJ request_handler_object = *(REQ_H_OBJ *)args;
    int client_fd = request_handler_object.client_fd;

    char send_message[1028] = "server ack :0 \n";

    while (1) {
        char rec_buffer[1028];
        
        CLIENT_REQUEST client_request;

        int rec_status = recv(client_fd, client_request.query, sizeof(client_request.query), 0);
        if (rec_status < 0) {
            printf("Failed to read from fd, receive failed");
            return NULL;
        }
        printf("received = %s \n", client_request.query);
        if( strcmp(client_request.query, "exit\n") == 0 ){
            printf("disconnecting client... \n");
            close(client_fd);
            return NULL;
        }
        write(request_handler_object.pipe_fds[1], &client_request, sizeof(CLIENT_REQUEST));
        // in_meme_entry (client_request.query);
        int send_status = send(client_fd, send_message, sizeof(send_message), 0);
    }

    return NULL;
}