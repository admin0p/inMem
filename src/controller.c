#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"includes/controller.h"
#include"includes/handler.h"
#include "includes/input_controller.h"

/**
 * @brief
 * This is the command store 
 * All valid commands are stored here
 * refer to input_controller.h for the structure definition
 * command, argument_count, command_index_number
*/
const command_schema COMMANDS[20] = {
    {"GET", 1, 1},
    {"SET", 2, 2},
    {"exit", 0, 0},
    {"INFO", 1, 3}
};

int get_command_key(input_skeleton *input);

/**
 * @brief
 * This function breaks the input string into command and arguments and assigns to a structure input_skeleton
 * (refer to input_controller.h for the structure definition)
 * LOGIC:
 * 1. parse the string till a white space is encountered, the first word is the command and store it in the input_skeleton structure
 * 2. Repeat the process for the arguments and store them in a 2d array of the input_skeleton structure
 * Once done the get_command_key function is called to get the key index of the command
 * Then the input_handler function is called to handle the command
*/
int input_controller (char* user_input) {

    int command_counter = 0;
    int  argument_counter = 0;
    int command_length = 0;

    input_skeleton input_structure;

    memset(input_structure.command, 0, 1000);
    memset(input_structure.arguments, 0, 20 * 1024 * 2);
    input_structure.argument_count = 0;

    for(int i = 0; i < 1000; i ++){

        if(user_input[i] == '\n'){
            break;
        }

        if(command_counter == 0 ){
            
            command_length++;
            
            if(user_input[i] == ' '){
                command_counter = 1;
                continue;
            }

            input_structure.command[i] = user_input[i];
            
            continue;
        }

        else{
            if(user_input[i] == ' '){
                input_structure.argument_count++;
                argument_counter = 0;
                continue;
            }
            input_structure.arguments[input_structure.argument_count][argument_counter] = user_input[i];
            argument_counter++;
        }

    }
    
    int key_id = get_command_key(&input_structure);
    input_handler(key_id, &input_structure);
    return 0;
}

/**
 * @brief
 * This function compares the command in input_skeleton with the command store and returns the index of the command
 * if the command is not found, it returns -1 with a message
 * @param input_skeleton *input 
*/
int get_command_key(input_skeleton *input){

    for (int i = 0; i < 20; i++)
    {
        if (strcmp(input->command, COMMANDS[i].command) == 0)
        {
            if ((COMMANDS[i].argument_count > 0) && (input->argument_count != COMMANDS[i].argument_count - 1))
            {
                printf("Invalid number of arguments for %s\n", input->command);
                return -1;
            }
            return COMMANDS[i].command_index;
        }
    }
    printf("Invalid command\n");
    return -1;
}