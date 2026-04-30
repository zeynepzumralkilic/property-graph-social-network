#ifndef VERTEX_H
#define VERTEX_H

#define MAX_PROPERTIES 10

typedef struct Property {
    char key[50];
    char value[50];
} Property;

typedef struct Vertex {
    int id;
    char type[20]; // User, Photo, Event
    Property properties[MAX_PROPERTIES];
    int propertyCount;
    struct Vertex* next;
} Vertex;

Vertex* createVertex(int id, char type[]);
void addProperty(Vertex* v, char key[], char value[]);
void printVertex(Vertex* v);

#endif
