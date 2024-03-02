#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#include"includes/controller.h"
#include"includes/handler.h"

int main () {

    int status = 1;

    while(status == 1) {
        char query[1024*28];
        printf("inMem=>");
        fgets(query, 1024*28, stdin);
        input_controller(query);
    }
    return 0;    
}