#include <stdio.h>
#include <cs50.h>

void gen(int j, char block);
void row(int spaces, int blocks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height (Enter a value between 1 and 8): ");
    } while (n < 1 || 8 < n);

    int spaces = n - 1;
    int blocks = n - spaces;

    while (spaces > -1)
    {
        row(spaces, blocks);
        spaces--;
        blocks++;
    }
}

void gen(int j, char block)
{
    for (int i = 0; i < j; i++)
    {
        printf("%c", block);
    }
}

void row(int spaces, int blocks)
{
    gen(spaces, ' ');
    gen(blocks, '#');
    printf("  ");
    gen(blocks, '#');
    printf("\n");
}