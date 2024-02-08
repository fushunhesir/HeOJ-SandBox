//
// Created by Hanwei He on 2024/2/7.
//
#include "printf.h"

int main(int argc, char* argv[]) {
    if(argc == 0) {
        printf("at least one argument\n");
        return 1;
    }
    printf("I got the %s\n", argv[1]);
    printf("hello world!\n");
    return 0;
}