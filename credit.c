#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long number = get_long("credit card number: ");
    long original = number;
    long original1 = number;
    long original2 = number;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;

    // checksum
    number /= 10;
    for (int ii = 0; number > ii; number /= 100)
    {
        int last_digit = number % 10 * 2;

        if (last_digit < 10)
        {
            counter1 = counter1 + last_digit;
        }

        else if (last_digit >= 10)
        {
            int first_digit = last_digit / 10;
            int second_digit = last_digit % 10;

            counter1 = counter1 + first_digit + second_digit;
        }

        for (int jj = 0; original > jj; original /= 100)
        {
            last_digit = original % 10;
            counter2 = counter2 + last_digit;
        }
    }
    int valid = counter1 + counter2;
    int valid_last_digit = valid % 10;

    // determine the card type
    if (valid > 0 && valid_last_digit == 0)
    {
        for (int i = 0; i < original1;)
        {
            counter++;
            original1 = original1 / 10;
        }

        // American Expres
        if (counter == 15)
        {
            int AE_validation = original2 / 10000000000000;

            if (AE_validation == 34 || AE_validation == 37)
            {
                printf("AMEX\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        // VISA1
        else if (counter == 13)
        {
            int valid_visa = original2 / 1000000000000;
            if (valid_visa == 4)
            {
                printf("VISA\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else if (counter == 16)
        {
            int valid_visa_1 = original2 / 1000000000000000;
            int MC_validation = original2 / 100000000000000;

            // VISA2
            if (valid_visa_1 == 4)
            {
                printf("VISA\n");
            }

            // MasterCard
            else if (MC_validation == 51 || MC_validation == 52 || MC_validation == 53 || MC_validation == 54 || MC_validation == 55)
            {
                printf("MASTERCARD\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
