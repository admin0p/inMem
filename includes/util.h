/*
*use this file to define or add any utilities that you may need
*in your program. For example, you may want to define a constant
*or a function that you will use in multiple files. You can decare
*them here and define them in utilities.c and then include this
*/ 
#ifndef UTIL_H
#define UTIL_H

#define SUCCESS_STATUS 0
#define FAILURE_STATUS -1

void get_token(char *input_str, char * return_token, int size, const char *delim);

#endif