// CHALLENGE 1
// This is CS50
// Prompt user for 1-8 (inclusive) integer n and create right aligned pyramid


#include <stdio.h>
#include <cs50.h>

void space(int n);

int main(void)
{
    int n;

    do
    {
        n = get_int("Height: \n");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        space(n-i);
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
    printf("\n");
    }
}

void space(int n)
{
    for(int i = 0; i < n; i++)
    {
    printf(" ");
    }
}
