// CHALLENGE 3
// This is CS50
// Prompt user for float indicating amount of change owed and return an integer indicating the least amount of coins to fulfill the total

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;

    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    int cents = round(change * 100); //Convert dollar amount to cents

    int quarters = cents / 25; //Dollar coins not inclueded
    int dimes = (cents - 25 * quarters) / 10; //Creating separate variable for 25 * quarters would be verbose
    int nickels = (cents - (25 * quarters + 10 * dimes)) / 5;
    int pennies = (cents - (25 * quarters + 10 * dimes + 5 * nickels)) / 1;
    int coins = trunc(quarters + dimes + nickels + pennies);

    printf("%i\n", coins); //Print only the number of coins needed
}
