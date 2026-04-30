#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "edge.h"

typedef struct Graph {
    int numVertices;
    Vertex* vertexList;
    Edge** adjLists;
} Graph;

Graph* createGraph(int size);
void addVertex(Graph* graph, int id, char type[]);
void addEdge(Graph* graph, int src, int dest, char relation[]);
Vertex* findVertex(Graph* graph, int id);
void printGraph(Graph* graph);

#endif