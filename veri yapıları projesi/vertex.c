#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertex.h"

Vertex* createVertex(int id, char type[]) {
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    v->id = id;
    strcpy(v->type, type);
    v->propertyCount = 0;
    v->next = NULL;
    return v;
}

void addProperty(Vertex* v, char key[], char value[]) {
    if (v->propertyCount < MAX_PROPERTIES) {
        strcpy(v->properties[v->propertyCount].key, key);
        strcpy(v->properties[v->propertyCount].value, value);
        v->propertyCount++;
    }
}

void printVertex(Vertex* v) {
    printf("Vertex ID: %d, Type: %s\n", v->id, v->type);
    for (int i = 0; i < v->propertyCount; i++) {
        printf("  %s: %s\n", v->properties[i].key, v->properties[i].value);
    }
}