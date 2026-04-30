#ifndef EDGE_H
#define EDGE_H

typedef struct Edge {
    int dest;
    char relation[20]; // FRIEND, LIKES
    struct Edge* next;
} Edge;

Edge* createEdge(int dest, char relation[]);

#endif
