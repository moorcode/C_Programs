// CHALLENGE 2
// This is CS50
// Prompt user for 1-8 (inclusive) integer n and create right aligned pyramid beside left aligned pyramid with 2 spaces in between

#include <stdio.h>
#include <cs50.h>


void space(int n);
void left_pyramid(int i);

int main(void)
{
    int n;
    do
    {
        n = get_int("Please enter a height from 1 - 8: \n");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        space(n - i);
        left_pyramid(i);
        printf("  ");
        left_pyramid(i);
        printf("\n");
    }
}

void space(int n)
{
    for (int i = 1; i < n; i++)
    {
        printf(" ");
    }
}

void left_pyramid(int i)
{
    for (int j = 0; j <= i; j++)
    {
        printf("#");
    }
}
