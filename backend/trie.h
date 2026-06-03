#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];

    int isEndOfWord;

} TrieNode;

TrieNode* createTrieNode();

void insertTrie(TrieNode* root, char* word);

int searchTrie(TrieNode* root, char* word);

void printSuggestions(TrieNode* root,
                      char word[],
                      int level);

void autocomplete(TrieNode* root,
                  char* prefix);

#endif