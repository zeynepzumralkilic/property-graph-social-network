#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "graph.h"

void BFS(Graph* graph, int startID);
void DFS(Graph* graph, int startID);
void DFSUtil(Graph* graph, Node* node, int visited[]);
void searchNodesByType(Graph* graph,
                       const char* type);
void searchRelationships(
    Graph* graph,
    const char* relationType
);
void filteredBFS(
    Graph* graph,
    int startID,
    const char* relationType
);
int degreesOfSeparation(
    Graph* graph,
    int startID,
    int targetID
);
void shortestPath(
    Graph* graph,
    int startID,
    int targetID
);                       
#endif
