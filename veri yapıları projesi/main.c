#include <stdio.h>
#include "graph.h"

int main() {
    Graph* graph = createGraph(5);

    addVertex(graph, 0, "User");
    addVertex(graph, 1, "User");

    Vertex* v = findVertex(graph, 0);
    addProperty(v, "name", "Ali");
    addProperty(v, "age", "21");

    addEdge(graph, 0, 1, "FRIEND");

    printGraph(graph);

    return 0;
}