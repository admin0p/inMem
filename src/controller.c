/**
 * This file as the name suggest controls the flow of the program 
 *  > Breaks the user input and arranges it in a 2d ARRAY structure 
 *  > prints the structure as of now 
 *  > To dos
 *    -> create an input structure that has all meta data of the input 
 *    -> this structure will be passed on to the lex analysis to validate the input
 *    -> once done the query/ input  will be interpreted and executed
*/


#include<stdio.h>
#include<string.h>
#include "../includes/util.h"
#include "../includes/controller.h"

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
void input_breaker(char input_str[], char input_breakup[][ARGUMENT_MAX_SIZE], const char *delim)
{
    int i = 0; // input character iterator
    int j = 0; // input word iterator 
    int k = 0; // input breakup word character iterator
    int token_found = 0;

    while (i < INPUT_SIZE && j < ARGUMENT_COUNT && k < ARGUMENT_MAX_SIZE)
    {
       
        if(input_str[i] == NEXT_LINE_CHAR){
            input_breakup[j+1][0] = NEXT_LINE_CHAR;
            return;
        }

        if ( input_str[i] != *delim)
        {
            input_breakup[j][k] = input_str[i];
            k++;
        }
        else 
        {
            k = 0;
            j++;
        }
        i++;
    }
    return;
}

/**
 * This is just the i/o controller that controls the flow of the program
*/
void input_controller(char * input) {

    char inputs_structure[ARGUMENT_COUNT][ARGUMENT_MAX_SIZE];

    memset(inputs_structure, 0, ARGUMENT_COUNT * ARGUMENT_MAX_SIZE);

    input_breaker(input, inputs_structure, DELIMETER);

    for(int j = 0; inputs_structure[j][0] != NEXT_LINE_CHAR && j < ARGUMENT_COUNT; j++ ) {
        printf("%d input => %s \n",j, inputs_structure[j]);
    }
}