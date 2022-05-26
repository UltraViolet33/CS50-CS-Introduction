#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_char(char *s, char c);
int calculate_index(int letter, int sentence, int word);

int main(void)
{
    int letters;
    int words;
    int sentences;
    int number_letter_per_word;
    int number_sentences_per_word;

    int grade;
    // get user input
    string text = get_string("Text : ");

    // count the number of letters
    letters = count_letters(text);

    // count the number of words
    words = count_words(text);

    // count the number of sentences
    sentences = count_sentences(text);

    grade = calculate_index(letters, sentences, words);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// count the letters in a string
// return int number_letters
int count_letters(string text)
{
    int i;
    int number_letters = 0;

    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            number_letters += 1;
        }
    }

    return number_letters;
}

// count the words in a string
// return int number_words
int count_words(string text)
{
    int i;
    int number_words = 0;

    for (i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            number_words += 1;
        }
    }

    return number_words + 1;
}

// count the number of sentences in a string
//  return int number_sentences
int count_sentences(string text)
{
    int sentences = 0;
    string test = text;

    int count_period = count_char(test, '.');

    int count_interro = count_char(test, '?');

    int count_excla = count_char(test, '!');

    sentences = count_interro + count_period + count_excla;

    return sentences;
}

// count the number of c in a s
int count_char(char *s, char c)
{
    int length = strlen(s);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
         if (s[i] == c)
        {
            count++;
        }

    }
       
    return count;
}

int calculate_index(int letters, int sentences, int words)
{
    float L = 100.0000 * letters / words;
    float S = 100.0000 * sentences / words;
    float f = 0.0588 * L - 0.296 * S - 15.8;

    return (int)round(f);
}
