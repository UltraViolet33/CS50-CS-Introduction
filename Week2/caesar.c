#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void display_error();
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    int key;
    string text_user;

    if (argc != 2)
    {
        display_error();
        return 1;
    }

    if (only_digits(argv[1]) == 1)
    {
        display_error();
        return 1;
    }

    key = atoi(argv[1]);
    text_user = get_string("plaintext:  ");

    for (int i = 0; i < strlen(text_user); i++)
    {
        char letter = rotate(text_user[i], key);
        text_user[i] = letter;
    }

    printf("ciphertext: %s\n", text_user);

    return 0;
}

void display_error()
{
    printf("Usage: ./caesar key\n");
}

// Check if the string is a digit
bool only_digits(string s)
{
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Rotates the char c by the key i
char rotate(char c, int i)
{
    int new_letter;
    int start;

    if (islower(c) != 0)
    {
        start = (int)c - 97;
        new_letter = (start + i) % 26;
        new_letter += 97;
    }
    else if (isupper(c) != 0)
    {
        start = (int)c - 65;
        new_letter = (start + i) % 26;
        new_letter += 65;
    }
    else
    {
        return c;
    }

    new_letter = (char)new_letter;
    return new_letter;
}