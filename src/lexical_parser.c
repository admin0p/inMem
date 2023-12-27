#include "../includes/lexical_parser.h"
#include "../includes/util.h"
#include "../includes/token.h"
#include <string.h>
#include <stdio.h>

const token_struct KEY_SPACE[TOKENS_COUNT] =
    {
        {"GET", 1, 1, 0},
        {"SET", 2, 2, 0}
    };

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
void input_parser(char input_str[], const char *delim, input_metadata *metadata_pointer)
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
            if (j == COMMAND_POSITION)
            {
                (*metadata_pointer).command[i] = input_str[i];
            }
            else
            {
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

int input_validator(input_metadata *input)
{
    for (int index = 0; index < TOKENS_COUNT; index++)
    {

        if (strcmp(input->command, KEY_SPACE[index].token) == 0)
        {
            if (input->argument_count != KEY_SPACE[index].argument_count)
            {
                printf("Invalid number of arguments for %d, %d\n", input->argument_count, KEY_SPACE[index].argument_count);
                return KEY_VALIDATION_FAILED;
            }
            return KEY_SPACE[index].key_id;
        }
    }

    return KEY_VALIDATION_FAILED;
}
