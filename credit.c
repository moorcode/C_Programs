// CHALLENG 4
// This is CS50
// Objective: Prompt user for valid credit card number and return card type (VISA, AMEX, MASTERCARD) if number matches formatting and passes Luhn's Algorithm

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    string check;
    int checksum(long card_number);
    int first_digit;
    int get_first_digit(long card_number);
    int first_two_digits;
    int get_first_two_digits(long card_number);
    string card_type;

    /* Prompt user for card number with no hyphens;
       Use get_long for up to 16 digits */

    do
    {
        card_number = get_long("Please enter your card number (without hyphens): ");
    }
    while (card_number < 0);

    /* Calulate checksum
        Multiply every other digit by 2, starting with second to last digit;
        Add those products' digits together;
        Add the sum to the sum of the digits that weren't multiplied by 2. */

    checksum(card_number);
    if (checksum(card_number) == 0)
    {
        check = "true";
    }
    else
        check = "false";

    /* Determine first digit to recognize a Visa card */
    /* Determine the first two digits to recognize MAstercard and Amex */

    first_digit = get_first_digit(card_number);
    first_two_digits = get_first_two_digits(card_number);

    /* Determine the total digits in card_number */

    int digits = 0;
    while (card_number > 0)
    {
        card_number /= 10;
        digits++;
    }

    /* Determine card type */
    /* According to the instructions:
        Mastercard has 16 digits and begins with 51, 52, 53, 54, 55;
        Visa has 13 and 16 digits and begins with 4;
        Amex has 15 digits and begins with 34, 37. */
    /* Cards that don't match the Mastercard, Visa, Amex format
        are considered invalid in teh context of this program.*/


    if ((checksum(card_number) == 0) && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 54
         || first_two_digits == 54|| first_two_digits == 55) && (digits == 16))
    {
        card_type = "MASTERCARD";
    }
    else if ((checksum(card_number) == 0) && (first_digit == 4) && (digits == 16 || digits == 13))
    {
        card_type = "VISA";
    }
    else if ((checksum(card_number) == 0) && (first_two_digits == 34 || first_two_digits == 37) && (digits == 15))
    {
        card_type = "AMEX";
    }
    else
    {
        card_type = "INVALID";
    }

    /* Printing out more data for fun */

    // printf("Checksum passed:\n %s\n\n Number of digits on card:\n %i\n\n First digit on card:\n %i\n\n First two digts on card:\n %i\n\n Card type:\n %s\n",
    //       check, digits, first_digit, first_two_digits,
    //       card_type);

        printf("card_number: %li\n\n product sum: %i\n\n sum: %i\n\n", card_number, product_sum, sum);
}

int get_first_digit(long card_number)
{
    while (card_number >= 10)
    {
        card_number /= 10;
    }
    return card_number;
}

int get_first_two_digits(long card_number)
{
    while (card_number >= 100)
    {
        card_number /= 10;
    }
    return card_number;
}

int checksum(long card_number)
{
    int product_sum = 0;
    int sum = 0;
    while (card_number > 0)
    {
        sum += (card_number % 10);
        card_number /= 10; //Divide by 10 to remove last value
        product_sum += (card_number % 10) * 2; //Modulo by 10 to remove all values except last (second to last)
    }
    return (sum + product_sum) % 10;
}
