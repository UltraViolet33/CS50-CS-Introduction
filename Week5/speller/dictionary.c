// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
void free_node(node *n);

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

int word_count = 0;

// Hash table
node *table[N];



// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_num = hash(word);

    node *current = table[hash_num];

    while (current != NULL)
    {
        if(strcasecmp(current->word, word) == 0)
        {
            return true;
        }

         current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(dict, "%s", word) != EOF)
    {
        node *tmp = malloc(sizeof(node));

        if(tmp == NULL)
        {
            return false;
        }

        strcpy(tmp->word, word);

        int hash_number = hash(word);

        if(table[hash_number] == NULL)
        {
            tmp->next = NULL;
        }
        else
        {
            tmp->next = table[hash_number];
        }

        table[hash_number] = tmp;
        word_count += 1;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            free_node(table[i]);
        }
    }
    return true;
}

void free_node(node *n)
{
    if(n->next != NULL)
    {
        free_node(n->next);
    }

    free(n);
}