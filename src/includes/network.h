#ifndef NETWORK_H
#define NETWORK_H

typedef struct REQUEST_HANDLER_OBJ {
    int client_fd;
    int pipe_fds [2];
} REQ_H_OBJ;

typedef  struct CLIENT_REQUEST {
    int client_fd;
    char query[1024*28];
} CLIENT_REQUEST;

#endif