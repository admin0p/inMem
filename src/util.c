#include<stdio.h>
#include<string.h>
#include"../includes/util.h"

void get_token(char *input_str, char * return_token, int size, const char *delim)
{
    int i = 0 ;
    while ( input_str[i] != *delim && i < size ){
        return_token[i] = input_str[i];
        i++;
    }
}