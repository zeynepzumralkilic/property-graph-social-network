#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    TYPE_USER,
    TYPE_PHOTO,
    TYPE_EVENT
} VertexType;

typedef struct Property
{
    char key[50];
    char value[100];
    struct Property *next;
} Property;

typedef struct Vertex
{
    int id;
    VertexType type;
    Property *properties;
} Vertex;

Vertex *createVertex(int id, VertexType type)
{
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));
    newVertex->id = id;
    newVertex->type = type;
    newVertex->properties = NULL;
    return newVertex;
}

void addProperty(Vertex *vertex, const char *key, const char *value)
{
    Property *newProp = (Property *)malloc(sizeof(Property));
    strcpy(newProp->key, key);
    strcpy(newProp->value, value);
    newProp->next = NULL;

    if (vertex->properties == NULL)
    {
        vertex->properties = newProp;
    }
    else
    {
        Property *temp = vertex->properties;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newProp;
    }
}

void freeVertex(Vertex *vertex)
{
    Property *temp = vertex->properties;
    Property *nextProp;
    while (temp != NULL)
    {
        nextProp = temp->next;
        free(temp);
        temp = nextProp;
    }
    free(vertex);
}
