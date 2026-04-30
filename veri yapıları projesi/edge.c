#include <stdlib.h>
#include <string.h>
#include "edge.h"

Edge* createEdge(int dest, char relation[]) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->dest = dest;
    strcpy(e->relation, relation);
    e->next = NULL;
    return e;
}