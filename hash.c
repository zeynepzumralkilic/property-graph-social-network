#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

HashTable* createHashTable()
{
    HashTable* hashTable =
        (HashTable*)malloc(sizeof(HashTable));

    for(int i=0;i<TABLE_SIZE;i++)
    {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertHash(HashTable* hashTable, Node* node)
{
    int index = hashFunction(node->id);

    HashNode* newNode =
        (HashNode*)malloc(sizeof(HashNode));

    newNode->key = node->id;
    newNode->node = node;

    newNode->next = hashTable->table[index];

    hashTable->table[index] = newNode;
}

Node* searchHash(HashTable* hashTable, int key)
{
    int index = hashFunction(key);

    HashNode* current =
        hashTable->table[index];

    while(current != NULL)
    {
        if(current->key == key)
        {
            return current->node;
        }

        current = current->next;
    }

    return NULL;
}

void printHashTable(HashTable* hashTable)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        HashNode* current =
            hashTable->table[i];

        if(current != NULL)
        {
            printf("Bucket %d:\n",i);

            while(current != NULL)
            {
                printf("  ID = %d\n",
                       current->key);

                current = current->next;
            }
        }
    }
}