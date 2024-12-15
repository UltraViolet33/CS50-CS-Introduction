#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number;
    int i;
    int j;
    int k;
    int l;

    do
    {
        number = get_int("Height : ");
    } while (number <= 0 || number > 8);

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

        printf("  ");

        for (l = 0; l < i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}