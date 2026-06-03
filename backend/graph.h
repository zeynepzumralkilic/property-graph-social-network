#ifndef GRAPH_H
#define GRAPH_H

#define MAX_TYPE 20
#define MAX_KEY 50
#define MAX_VALUE 100
#define MAX_RELATION 20

typedef struct Property {
    char key[MAX_KEY];
    char value[MAX_VALUE];
    struct Property* next;
} Property;

typedef struct Edge {
    int targetID;
    char relationType[MAX_RELATION];

    Property* properties;

    struct Edge* next;
} Edge;

typedef struct Node {
    int id;
    char type[MAX_TYPE];

    Property* properties;

    Edge* edges;

    struct Node* next;
} Node;

typedef struct Graph {
    Node* nodeList;
} Graph;

Graph* createGraph();

Node* createNode(int id, const char* type);

void addNode(Graph* graph, int id, const char* type);

Node* findNode(Graph* graph, int id);

void addEdge(Graph* graph,
             int sourceID,
             int targetID,
             const char* relationType);

void printGraph(Graph* graph);

#endif