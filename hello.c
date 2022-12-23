#include <stdio.h>
#include <cs50.h>

// Compile using: clang hello.c -o hello -lcs50

int main (void)
{

    string answer = get_string("What's your name? \n");
    printf("Hello, %s!", answer);
    printf("\n");
}