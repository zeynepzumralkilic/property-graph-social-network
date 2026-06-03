#include <stdio.h>
#include "graph.h"
#include "hash.h"
#include "queue.h"
#include "algorithms.h"
#include "trie.h"

int main()
{
    Graph* socialGraph = createGraph();

    addNode(socialGraph,1,"User");
    addNode(socialGraph,2,"User");
    addNode(socialGraph,3,"Photo");
    addNode(socialGraph,4,"Event");

    addEdge(socialGraph,1,2,"FRIEND");
    addEdge(socialGraph,1,3,"LIKES");
    addEdge(socialGraph,2,4,"ATTENDS");

    printGraph(socialGraph);

    printf("\n\n===== HASH TABLE =====\n");

    HashTable* hashTable =
        createHashTable();

    Node* current =
        socialGraph->nodeList;

    while(current != NULL)
    {
        insertHash(hashTable,current);

        current = current->next;
    }

    printHashTable(hashTable);

    printf("\n===== ARAMA =====\n");

    Node* found =
        searchHash(hashTable,3);

    if(found != NULL)
    {
        printf("Bulundu!\n");
        printf("ID: %d\n",found->id);
        printf("Type: %s\n",found->type);
    }
    printf("\n===== QUEUE TEST =====\n");

Queue* q = createQueue();

enqueue(q, findNode(socialGraph,1));
enqueue(q, findNode(socialGraph,2));
enqueue(q, findNode(socialGraph,3));

while(!isEmpty(q))
{
    Node* n = dequeue(q);

    printf("Node ID: %d Type:%s\n",
           n->id,
           n->type);
}
BFS(socialGraph,1);
DFS(socialGraph,1);

printf("\n===== TRIE TEST =====\n");

TrieNode* trieRoot =
    createTrieNode();

insertTrie(trieRoot,"Ali");
insertTrie(trieRoot,"Alper");
insertTrie(trieRoot,"Alp");
insertTrie(trieRoot,"Ayse");
insertTrie(trieRoot,"Ahmet");

printf("Prefix: Al\n");

autocomplete(trieRoot,"Al");

searchNodesByType(
    socialGraph,
    "User"
);
searchRelationships(
    socialGraph,
    "FRIEND"
);
filteredBFS(
    socialGraph,
    1,
    "FRIEND"
);
printf(
 "\nDistance = %d\n",
 degreesOfSeparation(
   socialGraph,
   1,
   4
 )
);
shortestPath(
    socialGraph,
    1,
    4
);
    return 0;
}
