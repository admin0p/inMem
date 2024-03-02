#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#define MAX_COMMAND_SIZE 1000
#define MAX_ARGUMENT_SIZE 1024 * 2
#define MAX_ARGUMENT_COUNT 20

typedef struct input_skeleton {
    char command[MAX_COMMAND_SIZE];
    int argument_count;
    char arguments[MAX_ARGUMENT_COUNT][MAX_ARGUMENT_SIZE]; 
} input_skeleton;

typedef struct command_schema {
    char command[MAX_COMMAND_SIZE];
    int argument_count;
    int command_index; 
} command_schema;

#endif