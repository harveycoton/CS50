#include <stdio.h>
#include <cs50.h>

// Compile using: clang hello.c -o hello -lcs50

int main (void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    printf("%i\n", x + y);
}