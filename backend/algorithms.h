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

// String buffer versiyonları (GUI için)
void BFS_toString(Graph* graph, int startID, char* buffer, int bufSize);
void DFS_toString(Graph* graph, int startID, char* buffer, int bufSize);
void shortestPath_toString(Graph* graph, int startID, int targetID, char* buffer, int bufSize);
void searchNodesByType_toString(Graph* graph, const char* type, char* buffer, int bufSize);
void searchRelationships_toString(Graph* graph, const char* relationType, char* buffer, int bufSize);

#endif
