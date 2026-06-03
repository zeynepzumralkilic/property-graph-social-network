#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

Graph* createGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->nodeList = NULL;

    return graph;
}

Node* createNode(int id, const char* type)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->id = id;

    strcpy(node->type, type);

    node->properties = NULL;
    node->edges = NULL;
    node->next = NULL;

    return node;
}

void addNode(Graph* graph, int id, const char* type)
{
    Node* newNode = createNode(id, type);

    newNode->next = graph->nodeList;

    graph->nodeList = newNode;
}

Node* findNode(Graph* graph, int id)
{
    Node* current = graph->nodeList;

    while(current != NULL)
    {
        if(current->id == id)
            return current;

        current = current->next;
    }

    return NULL;
}

void addEdge(Graph* graph,
             int sourceID,
             int targetID,
             const char* relationType)
{
    Node* source = findNode(graph, sourceID);

    if(source == NULL)
    {
        printf("Kaynak node bulunamadi!\n");
        return;
    }

    Edge* newEdge = (Edge*)malloc(sizeof(Edge));

    newEdge->targetID = targetID;

    strcpy(newEdge->relationType, relationType);

    newEdge->properties = NULL;

    newEdge->next = source->edges;

    source->edges = newEdge;
}

void printGraph(Graph* graph)
{
    Node* currentNode = graph->nodeList;

    while(currentNode != NULL)
    {
        printf("\nNode ID: %d", currentNode->id);
        printf(" Type: %s\n", currentNode->type);

        Edge* edge = currentNode->edges;

        while(edge != NULL)
        {
            printf("  --> %d (%s)\n",
                   edge->targetID,
                   edge->relationType);

            edge = edge->next;
        }

        currentNode = currentNode->next;
    }
}