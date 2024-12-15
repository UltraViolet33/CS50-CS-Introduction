#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_last_digit(long number);
int get_sum(long number);
int check_card(int final_number);
int get_first_digit(long number);
void get_card_name(long number);
int get_last_two_digits(long number);

int main(void)
{
    int sum_card = 0;
    int result = 0;
    string card_name = "";

    unsigned long number_card = get_long("Entrez votre numéro de carte : ");

    sum_card = get_sum(number_card);
    result = check_card(sum_card);

    if (result == 1)
    {
        get_card_name(number_card);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int get_last_digit(long number)
{
    int last_digit = number % 10;
    return last_digit;
}

int get_sum(long number)
{
    int last_digit;
    int double_last_digit;
    int new_double_digit;
    int first_sum = 0;
    int odd_sum = 0;
    int sum = 0;
    int count = 1;

    while (number > 0)
    {
        last_digit = get_last_digit(number);
        number = floor(number / 10);

        if (count % 2 == 0)
        {
            double_last_digit = last_digit * 2;

            if (double_last_digit > 9)
            {
                new_double_digit = get_last_digit(double_last_digit);
                double_last_digit = 1;
                first_sum = first_sum + new_double_digit + double_last_digit;
            }
            else
            {
                first_sum = first_sum + double_last_digit;
            }
        }
        else
        {
            odd_sum = odd_sum + last_digit;
        }
        sum = first_sum + odd_sum;
        count = count + 1;
    }

    return sum;
}

int check_card(int final_number)
{
    int veryfinal_number = get_last_digit(final_number);

    if (veryfinal_number == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void get_card_name(long number)
{
    string result = "";
    int first_digit;
    int last_two_digits;

    first_digit = get_first_digit(number);
    last_two_digits = get_last_two_digits(number);

    if (first_digit == 4 && number > 100000000000)
    {
        printf("VISA\n");
    }
    else if (last_two_digits == 37 || last_two_digits == 34)
    {
        printf("AMEX\n");
    }
    else if (last_two_digits == 51 || last_two_digits == 55)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_first_digit(long number)
{
    int last_digit;

    while (number > 0)
    {
        last_digit = get_last_digit(number);
        number = floor(number / 10);
    }

    return last_digit;
}

int get_last_two_digits(long number)
{
    int two_digits;

    while (number > 99)
    {
        two_digits = get_last_digit(number);
        number = floor(number / 10);
    }

    return number;
}
