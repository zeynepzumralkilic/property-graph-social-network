#ifndef HASH_H
#define HASH_H

#include "graph.h"

#define TABLE_SIZE 101

typedef struct HashNode {
    int key;
    Node* node;
    struct HashNode* next;
} HashNode;

typedef struct HashTable {
    HashNode* table[TABLE_SIZE];
} HashTable;

HashTable* createHashTable();

int hashFunction(int key);

void insertHash(HashTable* hashTable, Node* node);

Node* searchHash(HashTable* hashTable, int key);

void printHashTable(HashTable* hashTable);

#endif