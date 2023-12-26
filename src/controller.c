/**
 * This file as the name suggest controls the flow of the program
 *  > Breaks the user input and arranges it in a 2d ARRAY structure
 *  > prints the structure as of now
 *  > To dos
 *    -> create an input structure that has all meta data of the input
 *    -> this structure will be passed on to the lex analysis to validate the input
 *    -> once done the query/ input  will be interpreted and executed
 */

#include <stdio.h>
#include <string.h>
#include "../includes/util.h"
#include "../includes/controller.h"
#include "../includes/lexical_analyser.h"

typedef struct input_metadata {
    char command[TOKEN_SIZE];
    int argument_count;
    char arguments [ARGUMENT_COUNT] [ARGUMENT_MAX_SIZE];
} input_metadata;

/**
 * This function essentially converts the input i.e a single flow of string to a
 * 2d array with each word is stored in its own separate row
 * example
 * "SET key value"
 * iterator pov =>
 *   i -> each character in the array
 *   j -> on encountering delimeter j points to the next row in the matrix to differentiate words
 *   k -> points to each character in the word in a specific row
 */
void input_breaker(char input_str[], const char *delim, input_metadata * metadata_pointer)
{
    int i = 0; // input character iterator
    int j = 0; // input word iterator
    int k = 0; // input breakup word character iterator
    int token_found = 0;

    while (i < INPUT_SIZE && j < ARGUMENT_COUNT && k < ARGUMENT_MAX_SIZE)
    {

        if (input_str[i] == NEXT_LINE_CHAR)
        {   
            metadata_pointer->arguments[j + 1][0] = NEXT_LINE_CHAR;
            break;
        }

        if (input_str[i] != *delim)
        {
            if(j == COMMAND_POSITION){
                (*metadata_pointer).command[i] = input_str[i];
            }else{
                metadata_pointer->arguments[j - 1][k] = input_str[i];
            }
            
            k++;
        }
        else
        {
            k = 0;
            j++;
        }
        i++;
    }
    metadata_pointer->argument_count = j;
    return;
}

/**
 * This is just the i/o controller that controls the flow of the program
 */
void input_controller(char *input)
{

    input_metadata input_meta_data = {"", 0, {""}};

    // allocate 2d struct memory to store the input in a structured manner
    memset(input_meta_data.arguments, 0, ARGUMENT_COUNT * ARGUMENT_MAX_SIZE);

    input_breaker(input, DELIMETER, &input_meta_data);
    
}