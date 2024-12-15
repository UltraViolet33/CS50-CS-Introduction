#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int validate_key(string key);
int only_alpha(string s);
int no_repeated_characters(string s);
char cipher_character(char c, string key);

int main(int argc, string argv[])
{
    string key;
    string text;

    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    if (validate_key(argv[1]) == 1)
    {
        return 1;
    }

    key = argv[1];
    text = get_string("plaintext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = cipher_character(text[i], key);
    }

    printf("ciphertext: %s\n", text);

    return 0;
}

// Check the key argument
int validate_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (only_alpha(key) == 1)
    {
        printf("Key must only contain alphabetic characters.\n");
    }

    if (no_repeated_characters(key) == 1)
    {
        printf("Key must not contains repeated characters\n");
        return 1;
    }

    return 0;
}

// Check if the characters are only alphabetics
int only_alpha(string s)
{
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

// Check if there is no repeated characters in the string s
int no_repeated_characters(string s)
{
    char start_lowercase = 97;
    char start_uppercase = 65;
    int count_lowercase;
    int count_uppercase;
    char i;
    int j;

    for (i = 97; i < 123; i++)
    {
        count_lowercase = 0;
        count_uppercase = 0;

        for (j = 0; j < strlen(s); j++)
        {
            if (i == s[j])
            {
                count_lowercase += 1;
            }

            if (i - 32 == s[j])
            {
                count_lowercase += 1;
            }
        }

        if ((count_lowercase == 1 || count_uppercase == 0) && (count_lowercase == 0 || count_uppercase == 1))
        {
            return 1;
        }
    }

    return 0;
}

char cipher_character(char c, string key)
{
    int start_lowercase = 97;
    int start_uppercase = 65;
    int index = 0;

    if (isupper(c))
    {
        index = (int)c - start_uppercase;
        return toupper(key[index]);
    }
    else if (islower(c))
    {
        index = (int)c - start_lowercase;
        return tolower(key[index]);
    }
    else
    {
        return c;
    }
}