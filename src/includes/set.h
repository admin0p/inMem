#ifndef SET_H
#define SET_H

#define KEY_LIMIT 1000
#define VALUE_LIMIT 1024*4
#define KEY_SPACE_LIMIT 1024

int hash(char * key);

int set_key (char * key, char * value);

void get_key (char * key);

void get_key_info (char * key);

#endif