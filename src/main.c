/**
 * This is the main entry file used to handle user inputs
*/

#include <stdio.h>
#include <string.h>
#include "../includes/util.h"
#include "../includes/controller.h"


int main()
{
    char user_input[INPUT_SIZE];
    fgets(user_input, INPUT_SIZE, stdin);
    input_controller(user_input);    
    return SUCCESS_STATUS; // defined in util.h
}