#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "algorithms.h"

// Kuyruk (Queue) İşlemleri 

void enqueue(Queue* q, int id) {
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    if (temp == NULL) return;
    temp->vertex_id = id;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL) return -1; 
    QNode* temp = q->front;
    int id = temp->vertex_id;
    q->front = q->front->next;
    
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return id;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Algoritmalar

// BFS: Genişlik Öncelikli Arama (Katmanlı tarama ve mesafe ölçümü için)
void runBFS(int startNodeId, int totalNodes) {
    bool* visited = (bool*)calloc(totalNodes, sizeof(bool));
    Queue q = {NULL, NULL};

    if (visited == NULL) return;
    visited[startNodeId] = true;
    enqueue(&q, startNodeId);
    printf("\n[BFS] Baslatildi. Baslangic Dugumu ID: %d\n", startNodeId);

    while (!isQueueEmpty(&q)) {
        int currentId = dequeue(&q);
        printf("Ziyaret Edilen: %d\n", currentId);

        /* NOT: 1. Kisinin (graph-core) olusturacagi komsuluk listesi 
        yapisi tamamlandiginda buradaki dongu aktive edilecektir.
        
        Node* neighbor = getNeighbors(currentId);
        while(neighbor != NULL) {
            if(!visited[neighbor->id]) {
                visited[neighbor->id] = true;
                enqueue(&q, neighbor->id);
            }
            neighbor = neighbor->next;
        }
        */
    }
    free(visited);
    printf("[BFS] Tamamlandi.\n");
}

// DFS: Derinlik Öncelikli Arama (Recursive)
void runDFS(int currentId, bool visited[]) {
    visited[currentId] = true;
    printf("DFS Ziyaret Etti, Dugum ID: %d\n", currentId);
}

// Filtreli Arama: Belirli bir turdeki (User, Photo, Event) dugumleri bulur
void searchWithFilter(int startNodeId, int targetType) {
    printf("\n[Filtreli Sorgu] Baslatildi. Hedef Tur: %d\n", targetType);
  
    // Traversal sirasinda Vertex->type kontrolu yaparak filtreleme saglanacak.
}
