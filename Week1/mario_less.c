#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // variables declaration
    int number;
    int i;
    int j;
    int k;

    //input number
    do
    {
        number = get_int("Height : ");
    }
    while (number <= 0 || number > 8);

    //drawing
    for (i = 1; i <= number; i++)
    {
        for (k = i; k < number; k++)
        {
            printf(" ");
        }

        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}