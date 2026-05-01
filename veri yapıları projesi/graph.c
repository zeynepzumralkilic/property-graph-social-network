#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph(int size) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = size;

    graph->adjLists = malloc(size * sizeof(Edge*));
    for (int i = 0; i < size; i++)
        graph->adjLists[i] = NULL;

    graph->vertexList = NULL;
    return graph;
}

void addVertex(Graph* graph, int id, char type[]) {
    Vertex* v = createVertex(id, type);
    v->next = graph->vertexList;
    graph->vertexList = v;
}

Vertex* findVertex(Graph* graph, int id) {
    Vertex* temp = graph->vertexList;
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void addEdge(Graph* graph, int src, int dest, char relation[]) {
    Edge* e = createEdge(dest, relation);
    e->next = graph->adjLists[src];
    graph->adjLists[src] = e;
}

void printGraph(Graph* graph) {
    Vertex* v = graph->vertexList;
    while (v) {
        printVertex(v);
        v = v->next;
    }

    printf("\nConnections:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* temp = graph->adjLists[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d(%s) -> ", temp->dest, temp->relation);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}