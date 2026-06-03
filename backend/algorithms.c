#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "queue.h"
#include <string.h>
void BFS(Graph* graph, int startID)
{
    Node* startNode = findNode(graph, startID);

    if(startNode == NULL)
    {
        printf("Baslangic node bulunamadi!\n");
        return;
    }

    int visited[1000] = {0};

    Queue* queue = createQueue();

    visited[startID] = 1;

    enqueue(queue, startNode);

    printf("\n===== BFS =====\n");

    while(!isEmpty(queue))
    {
        Node* current = dequeue(queue);

        printf("Node ID: %d Type: %s\n",
               current->id,
               current->type);

        Edge* edge = current->edges;

        while(edge != NULL)
        {
            int neighborID = edge->targetID;

            if(!visited[neighborID])
            {
                Node* neighbor =
                    findNode(graph, neighborID);

                if(neighbor != NULL)
                {
                    visited[neighborID] = 1;

                    enqueue(queue, neighbor);
                }
            }

            edge = edge->next;
        }
    }
}
void DFSUtil(Graph* graph, Node* node, int visited[])
{
    if(node == NULL)
        return;

    visited[node->id] = 1;

    printf("Node ID: %d Type: %s\n",
           node->id,
           node->type);

    Edge* edge = node->edges;

    while(edge != NULL)
    {
        int neighborID = edge->targetID;

        if(!visited[neighborID])
        {
            Node* neighbor =
                findNode(graph, neighborID);

            DFSUtil(graph,
                    neighbor,
                    visited);
        }

        edge = edge->next;
    }
}

void DFS(Graph* graph, int startID)
{
    Node* startNode =
        findNode(graph, startID);

    if(startNode == NULL)
    {
        printf("Baslangic node bulunamadi!\n");
        return;
    }

    int visited[1000] = {0};

    printf("\n===== DFS =====\n");

    DFSUtil(graph,
            startNode,
            visited);
}
void searchNodesByType(Graph* graph,
                       const char* type)
{
    printf("\n===== NODE SEARCH =====\n");

    Node* current =
        graph->nodeList;

    while(current != NULL)
    {
        if(strcmp(current->type,type)==0)
        {
            printf("ID: %d  Type: %s\n",
                   current->id,
                   current->type);
        }

        current = current->next;
    }
}
void searchRelationships(
    Graph* graph,
    const char* relationType
)
{
    printf(
      "\n===== RELATION SEARCH =====\n"
    );

    Node* node =
        graph->nodeList;

    while(node != NULL)
    {
        Edge* edge =
            node->edges;

        while(edge != NULL)
        {
            if(strcmp(edge->relationType,
                      relationType)==0)
            {
                printf(
                  "%d --> %d (%s)\n",
                  node->id,
                  edge->targetID,
                  edge->relationType
                );
            }

            edge = edge->next;
        }

        node = node->next;
    }
}
void filteredBFS(
    Graph* graph,
    int startID,
    const char* relationType
)
{
    Node* start =
        findNode(graph,startID);

    if(start==NULL)
        return;

    int visited[1000]={0};

    Queue* queue =
        createQueue();

    enqueue(queue,start);

    visited[startID]=1;

    printf(
      "\n===== FILTERED BFS =====\n"
    );

    while(!isEmpty(queue))
    {
        Node* current =
            dequeue(queue);

        printf(
          "ID:%d Type:%s\n",
          current->id,
          current->type
        );

        Edge* edge =
            current->edges;

        while(edge!=NULL)
        {
            if(strcmp(edge->relationType,
                      relationType)==0)
            {
                int nextID =
                    edge->targetID;

                if(!visited[nextID])
                {
                    Node* next =
                        findNode(
                            graph,
                            nextID
                        );

                    if(next!=NULL)
                    {
                        visited[nextID]=1;

                        enqueue(
                          queue,
                          next
                        );
                    }
                }
            }

            edge=edge->next;
        }
    }
}
int degreesOfSeparation(
    Graph* graph,
    int startID,
    int targetID
)
{
    int visited[1000]={0};
    int distance[1000]={0};

    Queue* queue=createQueue();

    Node* start=findNode(graph,startID);

    if(start==NULL)
        return -1;

    enqueue(queue,start);

    visited[startID]=1;

    while(!isEmpty(queue))
    {
        Node* current=dequeue(queue);

        if(current->id==targetID)
            return distance[current->id];

        Edge* edge=current->edges;

        while(edge!=NULL)
        {
            int nextID=edge->targetID;

            if(!visited[nextID])
            {
                Node* next=
                    findNode(graph,nextID);

                if(next!=NULL)
                {
                    visited[nextID]=1;

                    distance[nextID]=
                        distance[current->id]+1;

                    enqueue(queue,next);
                }
            }

            edge=edge->next;
        }
    }

    return -1;
}
void shortestPath(
    Graph* graph,
    int startID,
    int targetID
)
{
    int visited[1000]={0};
    int parent[1000];

    for(int i=0;i<1000;i++)
        parent[i]=-1;

    Queue* queue=createQueue();

    Node* start=
        findNode(graph,startID);

    enqueue(queue,start);

    visited[startID]=1;

    while(!isEmpty(queue))
    {
        Node* current=
            dequeue(queue);

        if(current->id==targetID)
            break;

        Edge* edge=
            current->edges;

        while(edge!=NULL)
        {
            int nextID=
                edge->targetID;

            if(!visited[nextID])
            {
                visited[nextID]=1;

                parent[nextID]=
                    current->id;

                enqueue(
                    queue,
                    findNode(
                        graph,
                        nextID
                    )
                );
            }

            edge=edge->next;
        }
    }

    printf(
      "\n===== SHORTEST PATH =====\n"
    );

    int path[100];
    int count=0;

    int current=targetID;

    while(current!=-1)
    {
        path[count++]=current;

        current=
            parent[current];
    }

    for(int i=count-1;i>=0;i--)
    {
        printf("%d",path[i]);

        if(i!=0)
            printf(" -> ");
    }

    printf("\n");
}

/* ===== GUI için string buffer versiyonları ===== */

void BFS_toString(Graph* graph, int startID, char* buffer, int bufSize)
{
    buffer[0] = '\0';
    int offset = 0;

    Node* startNode = findNode(graph, startID);
    if(startNode == NULL)
    {
        snprintf(buffer, bufSize, "Node %d bulunamadi!", startID);
        return;
    }

    int visited[1000] = {0};
    Queue* queue = createQueue();
    visited[startID] = 1;
    enqueue(queue, startNode);

    offset += snprintf(buffer + offset, bufSize - offset, "BFS: ");

    int first = 1;
    while(!isEmpty(queue))
    {
        Node* current = dequeue(queue);

        if(!first)
            offset += snprintf(buffer + offset, bufSize - offset, " -> ");
        offset += snprintf(buffer + offset, bufSize - offset, "%d", current->id);
        first = 0;

        Edge* edge = current->edges;
        while(edge != NULL)
        {
            int neighborID = edge->targetID;
            if(!visited[neighborID])
            {
                Node* neighbor = findNode(graph, neighborID);
                if(neighbor != NULL)
                {
                    visited[neighborID] = 1;
                    enqueue(queue, neighbor);
                }
            }
            edge = edge->next;
        }
    }
}

void DFSUtil_toString(Graph* graph, Node* node, int visited[], char* buffer, int bufSize, int* offset, int* first)
{
    if(node == NULL) return;

    visited[node->id] = 1;

    if(!(*first))
        *offset += snprintf(buffer + *offset, bufSize - *offset, " -> ");
    *offset += snprintf(buffer + *offset, bufSize - *offset, "%d", node->id);
    *first = 0;

    Edge* edge = node->edges;
    while(edge != NULL)
    {
        int neighborID = edge->targetID;
        if(!visited[neighborID])
        {
            Node* neighbor = findNode(graph, neighborID);
            DFSUtil_toString(graph, neighbor, visited, buffer, bufSize, offset, first);
        }
        edge = edge->next;
    }
}

void DFS_toString(Graph* graph, int startID, char* buffer, int bufSize)
{
    buffer[0] = '\0';
    int offset = 0;

    Node* startNode = findNode(graph, startID);
    if(startNode == NULL)
    {
        snprintf(buffer, bufSize, "Node %d bulunamadi!", startID);
        return;
    }

    int visited[1000] = {0};
    offset += snprintf(buffer + offset, bufSize - offset, "DFS: ");

    int first = 1;
    DFSUtil_toString(graph, startNode, visited, buffer, bufSize, &offset, &first);
}

void shortestPath_toString(Graph* graph, int startID, int targetID, char* buffer, int bufSize)
{
    buffer[0] = '\0';
    int offset = 0;

    int visited[1000] = {0};
    int parent[1000];
    for(int i = 0; i < 1000; i++)
        parent[i] = -1;

    Queue* queue = createQueue();
    Node* start = findNode(graph, startID);

    if(start == NULL)
    {
        snprintf(buffer, bufSize, "Node %d bulunamadi!", startID);
        return;
    }

    enqueue(queue, start);
    visited[startID] = 1;

    int found = 0;
    while(!isEmpty(queue))
    {
        Node* current = dequeue(queue);
        if(current->id == targetID)
        {
            found = 1;
            break;
        }

        Edge* edge = current->edges;
        while(edge != NULL)
        {
            int nextID = edge->targetID;
            if(!visited[nextID])
            {
                visited[nextID] = 1;
                parent[nextID] = current->id;
                enqueue(queue, findNode(graph, nextID));
            }
            edge = edge->next;
        }
    }

    if(!found)
    {
        snprintf(buffer, bufSize, "Yol bulunamadi: %d -> %d", startID, targetID);
        return;
    }

    int path[100];
    int count = 0;
    int current = targetID;
    while(current != -1)
    {
        path[count++] = current;
        current = parent[current];
    }

    offset += snprintf(buffer + offset, bufSize - offset, "Shortest: ");
    for(int i = count - 1; i >= 0; i--)
    {
        offset += snprintf(buffer + offset, bufSize - offset, "%d", path[i]);
        if(i != 0)
            offset += snprintf(buffer + offset, bufSize - offset, " -> ");
    }
}

void searchNodesByType_toString(Graph* graph, const char* type, char* buffer, int bufSize)
{
    buffer[0] = '\0';
    int offset = 0;

    Node* current = graph->nodeList;
    offset += snprintf(buffer + offset, bufSize - offset, "%s nodes: ", type);

    int first = 1;
    while(current != NULL)
    {
        if(strcmp(current->type, type) == 0)
        {
            if(!first)
                offset += snprintf(buffer + offset, bufSize - offset, ", ");
            offset += snprintf(buffer + offset, bufSize - offset, "%d", current->id);
            first = 0;
        }
        current = current->next;
    }
}

void searchRelationships_toString(Graph* graph, const char* relationType, char* buffer, int bufSize)
{
    buffer[0] = '\0';
    int offset = 0;

    Node* node = graph->nodeList;
    offset += snprintf(buffer + offset, bufSize - offset, "%s: ", relationType);

    int first = 1;
    while(node != NULL)
    {
        Edge* edge = node->edges;
        while(edge != NULL)
        {
            if(strcmp(edge->relationType, relationType) == 0)
            {
                if(!first)
                    offset += snprintf(buffer + offset, bufSize - offset, ", ");
                offset += snprintf(buffer + offset, bufSize - offset, "%d->%d", node->id, edge->targetID);
                first = 0;
            }
            edge = edge->next;
        }
        node = node->next;
    }
}