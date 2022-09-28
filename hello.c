/*
Hello World!

Build:

gcc -O -Wall -o hello hello.c hello_message.c
*/
#include <stdio.h>
#include <stdlib.h>

#include "hello.h"

int main(int argc, char **argv)
{
    printf("%s\n", hello_message);
    exit(0);
}