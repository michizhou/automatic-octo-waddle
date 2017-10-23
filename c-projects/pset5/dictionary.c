/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
 
 int words = 0;
 
 typedef struct node
 {
    bool is_word;
    struct node* children[27];
 }
 node;
 
 node* root;
 
bool check(const char* word)
{
    node* curr = root;
    int i = 0;
    
    while (word[i] != '\0')
    {
        char input = word[i];
        
        if (word[i] == '\'')
        {
            input = 'z' + 1;
        }
        
        int num = tolower(input) - 'a';
        
        if (curr->children[num] != NULL)
        {
            curr = curr->children[num];
            i++;
        }
        else
        {
            return false;
        }
    }
    
    if (curr->is_word == true)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    root = calloc(1, sizeof(node));
    int c = 0;
    node* curr = NULL;
    
    while (fgetc(dict) != EOF)
    {
        fseek(dict, -1, SEEK_CUR);
        curr = root;
        
        for (c = fgetc(dict); c != '\n'; c = fgetc(dict))
        {
            if (c == '\'')
            {
                c = 'z' + 1;
            }
            if (curr->children[c - 'a'] == NULL)
            {
                curr->children[c - 'a'] = calloc(1, sizeof(node));
                curr = curr->children[c - 'a'];
            }
            else
            {
                curr = curr->children[c - 'a'];
            }
        
        }
        curr->is_word = true;
        words++;
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool freeNode(node* now)
{    
    for (int j = 0; j < 27; j++)
    {
        if (now->children[j] != NULL)
        {
            freeNode(now->children[j]);
        }
    }
    free(now);
    return true;
} 
bool unload(void)
{
    return freeNode(root);
}
