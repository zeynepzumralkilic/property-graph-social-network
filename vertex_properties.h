#ifndef VERTEX_PROPERTIES_H
#define VERTEX_PROPERTIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Düğüm Türleri
typedef enum
{
    TYPE_USER,
    TYPE_PHOTO,
    TYPE_EVENT
} VertexType;

// 2. Özellikler (Property) Bağlı Liste Yapısı
typedef struct Property
{
    char key[50];
    char value[100];
    struct Property *next;
} Property;

// 3. Ana Düğüm (Vertex) Yapısı
typedef struct Vertex
{
    int id;
    VertexType type;
    Property *properties;
} Vertex;

// Fonksiyon Prototipleri (Sadece isimleri)
Vertex *createVertex(int id, VertexType type);
void addProperty(Vertex *vertex, const char *key, const char *value);
void freeVertex(Vertex *vertex);

#endif