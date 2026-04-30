/* hash_table.h - Property Graph dugumlerini int ID ile saklamak için hash tablosu */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HT_DEFAULT_CAPACITY 64
#define HT_LOAD_FACTOR_MAX 0.75

// Chaining için her bucket'taki linked list dugumu 
typedef struct Entry {
    int node_id;
    void *node_data;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    int size;
    int capacity;
} HashTable;

HashTable *ht_create(int capacity);
void ht_destroy(HashTable *ht);

void ht_put(HashTable *ht, int node_id, void *node_data);
void *ht_get(HashTable *ht, int node_id);
int ht_remove(HashTable *ht, int node_id);
int ht_contains(HashTable *ht, int node_id);

int ht_size(HashTable *ht);
void ht_print(HashTable *ht);

#endif   