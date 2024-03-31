#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<unistd.h>
#include<string.h>

int main (){

    int client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(1229);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connection_status = connect(client_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    printf("connection status %d\n", connection_status);
    if(connection_status < 0){
        printf("encountered error while connecting to server\n");
        return -1;
    }

    while (1)
    {
        char send_buff[1024], rcv_buffer[1028];
        fgets(send_buff, 1024, stdin);
        int send_status = send(client_socket_fd, send_buff, sizeof(send_buff), 0);
         if(strcmp(send_buff, "exit\n") == 0){
            printf("closing connection\n");
            close(client_socket_fd);
            break;
        }
        int recv_status = recv(client_socket_fd, rcv_buffer, sizeof(rcv_buffer), 0);
        printf("received message from server: %s\n", rcv_buffer);
    }

    close(client_socket_fd);
    return 0;
}