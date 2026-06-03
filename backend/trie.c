#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trie.h"

TrieNode* createTrieNode()
{
    TrieNode* node =
        (TrieNode*)malloc(sizeof(TrieNode));

    node->isEndOfWord = 0;

    for(int i=0;i<ALPHABET_SIZE;i++)
        node->children[i] = NULL;

    return node;
}

void insertTrie(TrieNode* root, char* word)
{
    TrieNode* current = root;

    for(int i=0; word[i] != '\0'; i++)
    {
        char c = tolower(word[i]);

        if(c < 'a' || c > 'z')
            continue;

        int index = c - 'a';

        if(current->children[index] == NULL)
        {
            current->children[index] =
                createTrieNode();
        }

        current = current->children[index];
    }

    current->isEndOfWord = 1;
}

int searchTrie(TrieNode* root, char* word)
{
    TrieNode* current = root;

    for(int i=0; word[i] != '\0'; i++)
    {
        char c = tolower(word[i]);

        if(c < 'a' || c > 'z')
            continue;

        int index = c - 'a';

        if(current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->isEndOfWord;
}

void printSuggestions(TrieNode* root,
                      char word[],
                      int level)
{
    if(root->isEndOfWord)
    {
        word[level] = '\0';

        printf("%s\n", word);
    }

    for(int i=0;i<26;i++)
    {
        if(root->children[i] != NULL)
        {
            word[level] = i + 'a';

            printSuggestions(
                root->children[i],
                word,
                level + 1
            );
        }
    }
}

void autocomplete(TrieNode* root,
                  char* prefix)
{
    TrieNode* current = root;

    for(int i=0; prefix[i] != '\0'; i++)
    {
        char c = tolower(prefix[i]);

        if(c < 'a' || c > 'z')
            continue;

        int index = c - 'a';

        if(current->children[index] == NULL)
        {
            printf("Sonuc bulunamadi.\n");
            return;
        }

        current = current->children[index];
    }

    char word[100];

    strcpy(word, prefix);

    printSuggestions(
        current,
        word,
        strlen(prefix)
    );
}