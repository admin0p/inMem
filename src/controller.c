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
#include "../includes/lexical_parser.h"
#include "../includes/executioner.h"

/**
 * This is just the i/o controller that controls the flow of the program
 */
void input_controller(char *input)
{

    input_metadata input_meta_data = {"", 0, {""}};

    // allocate 2d struct memory to store the input in a structured manner
    memset(input_meta_data.arguments, NULL_TERMINATOR, ARGUMENT_COUNT * ARGUMENT_MAX_SIZE);

    input_parser(input, DELIMETER, &input_meta_data);
    // validate the input
    int key_id = input_validator(&input_meta_data);

    if(key_id < 0 ){
        // handle this error
        return;
    }
    // execute the input
    query_executioner(key_id, input_meta_data.argument_count, input_meta_data.arguments);
}