#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"

typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();

void enqueue(Queue* queue, Node* node);

Node* dequeue(Queue* queue);

int isEmpty(Queue* queue);

#endif