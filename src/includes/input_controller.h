#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

// defining pre processing macros for the string limits to prevent overflows and seg faults
#define MAX_COMMAND_SIZE 1000
#define MAX_ARGUMENT_SIZE 1024 * 2
#define MAX_ARGUMENT_COUNT 20

/**
 * @brief
 * This structure is used to store the user input in a structured manner
 * command: stores the command
 * argument_count: stores the count of the args, this does not include the command
 * arguments: stores the argument in 2d array manner <space optimization needed>
 *  ->  [ [str arg 1 <char[MAX_ARGMENT_SIZE]>] 
 *        [str arg 2 <char[MAX_ARGMENT_SIZE]>]
 *        .... 
 *      ]
*/
typedef struct input_skeleton {
    char command[MAX_COMMAND_SIZE];
    int argument_count;
    char arguments[MAX_ARGUMENT_COUNT][MAX_ARGUMENT_SIZE]; 
} input_skeleton;

/**
 * @brief 
 * It is the schema for a command
 * command: String that stores the command itself
 * argument_count: valid number of arguments the command accepts
 * command_index: it is a mapped number (int) index to the command 
*/
typedef struct command_schema {
    char command[MAX_COMMAND_SIZE];
    int argument_count;
    int command_index; 
} command_schema;

#endif