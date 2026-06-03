#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue()
{
    Queue* queue =
        (Queue*)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int isEmpty(Queue* queue)
{
    return queue->front == NULL;
}

void enqueue(Queue* queue, Node* node)
{
    QueueNode* newNode =
        (QueueNode*)malloc(sizeof(QueueNode));

    newNode->data = node;
    newNode->next = NULL;

    if(queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

Node* dequeue(Queue* queue)
{
    if(isEmpty(queue))
        return NULL;

    QueueNode* temp = queue->front;

    Node* node = temp->data;

    queue->front = queue->front->next;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(temp);

    return node;
}