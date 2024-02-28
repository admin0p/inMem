#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include"controller.h"
#include"handler.h"

int main () {

    int status = 1; //  0 -stopped, >0 - running

    while(status == 1) {
        char query[1024*28];
        printf("inMem=>");
        fgets(query, 1024*28, stdin);
        input_controller(query);
    }
    return 0;    
}