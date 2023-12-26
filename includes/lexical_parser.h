#ifndef LEXICAL_PARSER_H
#define LEXICAL_PARSER_H

#define COMMAND_POSITION 0
#define TOKEN_SIZE 20
#define ARGUMENT_MAX_SIZE 20 
#define ARGUMENT_COUNT 10
#define DELIMETER " "

typedef struct input_parsed_metadata {
    char command[TOKEN_SIZE];
    int argument_count;
    char arguments [ARGUMENT_COUNT] [ARGUMENT_MAX_SIZE];
} input_metadata;


void input_parser(char input_str[], const char *delim, input_metadata * metadata_pointer);

int input_validator(input_metadata *input);

#endif