#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    printf("Number user : %d \n", cents);

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    printf("Quarters %d : \n", quarters);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    printf("Dimes : %d \n", dimes);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    printf("Nickels : %d \n", nickels);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    printf("Pennies : %d \n", pennies);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// get the user input
int get_cents(void)
{
    int number;
    do
    {
        number = get_int("Number : ");
    }
    while (number <= 0);

    return number;
}

// calculate the quarter
int calculate_quarters(int cents)
{
    int count = 0;
    int cent = cents;

    while (cent >= 25)
    {
        cent = cent - 25;
        count = count + 1;
    }
    return count;
}

//calculate the dimes
int calculate_dimes(int cents)
{
    int count = 0;
    int cent = cents;

    while (cent >= 10)
    {
        cent = cent - 10;
        count = count + 1;
    }
    return count;
}

//calculate the nickels
int calculate_nickels(int cents)
{
    int count = 0;
    int cent = cents;

    while (cent >= 5)
    {
        cent = cent - 5;
        count = count + 1;
    }
    return count;
}

//calculate the pennies
int calculate_pennies(int cents)
{
    int count = 0;
    int cent = cents;

    while (cent > 0)
    {
        cent = cent - 1;
        count = count + 1;
    }
    return count;
}
