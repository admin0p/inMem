#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"controller.h"
#include"handler.h"

typedef struct input_skeleton {
    char command[1000];
    int argument_count;
    char arguments[20][1024 * 2]; 
} input_skeleton;

typedef struct command_schema {
    char command[1000];
    int argument_count;
    int command_index; 
} command_schema;

const command_schema COMMANDS[20] = {
    {"GET", 1, 1},
    {"SET", 2, 2},
    {"exit", 0, 0}
};

int get_command_key(input_skeleton *input);

int input_controller (char* user_input) {

    // parse and bearkdown the string to a 2d array
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
    input_handler(key_id, input_structure.arguments[0], input_structure.arguments[1]);
    printf("Key id: %d\n", key_id);
    return 0;
}

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