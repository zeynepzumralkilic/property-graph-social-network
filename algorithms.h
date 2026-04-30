#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdbool.h>
#include "graph.h" 

// Zorunlu Veri Yapıları: Kuyruk (Queue)
typedef struct QNode {
    int vertex_id;
    struct QNode* next;
} QNode;

typedef struct {
    QNode *front, *rear;
} Queue;

// Kuyruk Fonksiyon Prototipleri
void enqueue(Queue* q, int id);
int dequeue(Queue* q);
bool isQueueEmpty(Queue* q);

/* Zorunlu Algoritmalar: BFS ve DFS
   Graf üzerinde arama ve filtreli tarama işlemleri.
*/

// Genişlik Öncelikli Arama: Bağlantı derecesi hesaplamak için
void runBFS(int startNodeId, int totalNodes);

// Derinlik Öncelikli Arama: Grafı katmanlı taramak için
void runDFS(int currentId, bool visited[]);

// Çok adımlı sorgular için filtreli arama 
void searchWithFilter(int startNodeId, int targetType);

#endif
