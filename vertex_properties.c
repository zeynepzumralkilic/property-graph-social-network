#include "vertex_properties.h" // Kendi oluşturduğumuz başlık dosyasını dahil ettik

// Yeni düğüm oluşturma
Vertex *createVertex(int id, VertexType type)
{
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));
    newVertex->id = id;
    newVertex->type = type;
    newVertex->properties = NULL;
    return newVertex;
}

// Düğüme yeni özellik ekleme
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

// Belleği temizleme
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