#include "raylib.h"
#include <string>

extern "C"
{
#include "../backend/graph.h"
#include "../backend/hash.h"
#include "../backend/queue.h"
#include "../backend/algorithms.h"
#include "../backend/trie.h"
}

std::string queryResult = "No query executed";

struct VisualNode
{
    int id;

    float x;
    float y;

    int type;
};

int main()
{
    InitWindow(1200, 700,
               "Property Graph Visualizer");

    SetTargetFPS(60);

    Graph* graph = createGraph();
    HashTable* hashTable = createHashTable();

    addNode(graph,1,"User");
    addNode(graph,2,"User");
    addNode(graph,3,"User");
    addNode(graph,4,"User");
    addNode(graph,5,"User");

    addNode(graph,101,"Photo");
    addNode(graph,102,"Photo");
    addNode(graph,103,"Photo");
    addNode(graph,104,"Photo");

    addNode(graph,201,"Event");
    addNode(graph,202,"Event");
    addNode(graph,203,"Event");

    insertHash(hashTable, findNode(graph,1));
    insertHash(hashTable, findNode(graph,2));
    insertHash(hashTable, findNode(graph,3));
    insertHash(hashTable, findNode(graph,4));
    insertHash(hashTable, findNode(graph,5));

    insertHash(hashTable, findNode(graph,101));
    insertHash(hashTable, findNode(graph,102));
    insertHash(hashTable, findNode(graph,103));
    insertHash(hashTable, findNode(graph,104));

    insertHash(hashTable, findNode(graph,201));
    insertHash(hashTable, findNode(graph,202));
    insertHash(hashTable, findNode(graph,203));

    // EDGE'LER (ilişkiler) - Backend algoritmalarının çalışması için gerekli
    // FRIEND ilişkileri
    addEdge(graph, 1, 2, "FRIEND");
    addEdge(graph, 2, 3, "FRIEND");
    addEdge(graph, 4, 5, "FRIEND");

    // LIKES ilişkileri
    addEdge(graph, 1, 101, "LIKES");
    addEdge(graph, 2, 102, "LIKES");
    addEdge(graph, 3, 103, "LIKES");
    addEdge(graph, 5, 104, "LIKES");

    // ATTENDS ilişkileri
    addEdge(graph, 4, 201, "ATTENDS");
    addEdge(graph, 5, 202, "ATTENDS");
    addEdge(graph, 3, 203, "ATTENDS");

    VisualNode nodes[] =
{
    // USERS (type=0)
    {1,150,120,0},
    {2,350,120,0},
    {3,550,120,0},
    {4,250,260,0},
    {5,450,260,0},

    // PHOTOS (type=1)
    {101,150,500,1},
    {102,350,500,1},
    {103,550,500,1},
    {104,750,500,1},

    // EVENTS (type=2)
    {201,750,120,2},
    {202,900,260,2},
    {203,750,400,2}
};

    int selectedNode = -1;

    while(!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    // NODE SEÇME

    for(int i=0;i<12;i++)
    {
        if(CheckCollisionPointCircle(
            mouse,
            Vector2{nodes[i].x,nodes[i].y},
            30))
        {
            selectedNode = nodes[i].id;
        }
    }

    // BFS BUTONU - Gerçek algoritma çağrısı
    if(CheckCollisionPointRec(
        mouse,
        Rectangle{20,20,120,40}))
    {
        char buffer[1024];
        BFS_toString(graph, 1, buffer, sizeof(buffer));
        queryResult = buffer;
    }

    // DFS BUTONU - Gerçek algoritma çağrısı
    if(CheckCollisionPointRec(
        mouse,
        Rectangle{160,20,120,40}))
    {
        char buffer[1024];
        DFS_toString(graph, 1, buffer, sizeof(buffer));
        queryResult = buffer;
    }

    // SHORTEST PATH - Gerçek algoritma çağrısı
    if(CheckCollisionPointRec(
        mouse,
        Rectangle{300,20,180,40}))
    {
        char buffer[1024];
        shortestPath_toString(graph, 1, 4, buffer, sizeof(buffer));
        queryResult = buffer;
    }

    // SOCIAL QUERY - Node ve ilişki arama
    if(CheckCollisionPointRec(
        mouse,
        Rectangle{500,20,180,40}))
    {
        char buf1[512];
        char buf2[512];
        searchNodesByType_toString(graph, "User", buf1, sizeof(buf1));
        searchRelationships_toString(graph, "FRIEND", buf2, sizeof(buf2));
        queryResult = std::string(buf1) + " | " + std::string(buf2);
    }
}
       
        BeginDrawing();
    


        ClearBackground(RAYWHITE);
        DrawText(
    "PROPERTY GRAPH VISUALIZER",
    320,
    80,
    30,
    BLACK
);
        DrawRectangle(20,20,120,40,DARKBLUE);
        DrawText("BFS",55,30,20,WHITE);

        DrawRectangle(160,20,120,40,DARKGREEN);
        DrawText("DFS",195,30,20,WHITE);

        DrawRectangle(300,20,180,40,MAROON);
        DrawText("SHORTEST PATH",315,30,20,WHITE);

        DrawRectangle(500,20,180,40,DARKPURPLE);
        DrawText("SOCIAL QUERY",520,30,20,WHITE);

        // FRIEND ilişkileri
DrawLine(150,120,350,120,BLACK);
DrawLine(350,120,550,120,BLACK);
DrawLine(250,260,450,260,BLACK);

// LIKES ilişkileri
DrawLine(150,120,150,500,BLACK);
DrawLine(350,120,350,500,BLACK);
DrawLine(550,120,550,500,BLACK);
DrawLine(450,260,750,500,BLACK);

// ATTENDS ilişkileri
DrawLine(250,260,750,120,BLACK);
DrawLine(450,260,900,260,BLACK);
DrawLine(550,120,750,400,BLACK);
        // FRIEND
DrawText("FRIEND",240,90,18,GREEN);
DrawText("FRIEND",440,90,18,GREEN);
DrawText("FRIEND",330,230,18,GREEN);

DrawText("LIKES",120,320,18,BLUE);
DrawText("LIKES",320,320,18,BLUE);
DrawText("LIKES",520,320,18,BLUE);
DrawText("LIKES",580,380,18,BLUE);

DrawText("ATTENDS",450,170,18,ORANGE);
DrawText("ATTENDS",650,240,18,ORANGE);
DrawText("ATTENDS",620,250,18,ORANGE);
// FRIEND oku
DrawTriangle(
    Vector2{400,150},
    Vector2{385,145},
    Vector2{385,155},
    GREEN
);

// LIKES oku
DrawTriangle(
    Vector2{300,300},
    Vector2{290,285},
    Vector2{280,295},
    BLUE
);

// ATTENDS oku
DrawTriangle(
    Vector2{500,300},
    Vector2{490,285},
    Vector2{480,295},
    ORANGE
);

        for(int i=0;i<12;i++)
        {
            if(nodes[i].type==0)
            {
                DrawCircle(
                    nodes[i].x,
                    nodes[i].y,
                    30,
                    GREEN
                );
            }

            if(nodes[i].type==1)
            {
                DrawRectangle(
                    nodes[i].x-30,
                    nodes[i].y-30,
                    60,
                    60,
                    BLUE
                );
            }

            if(nodes[i].type==2)
            {
                DrawTriangle(
                    {nodes[i].x,nodes[i].y-35},
                    {nodes[i].x-35,nodes[i].y+35},
                    {nodes[i].x+35,nodes[i].y+35},
                    ORANGE
                );
            }

            DrawText(
                TextFormat("%d",
                nodes[i].id),
                nodes[i].x-5,
                nodes[i].y-10,
                20,
                BLACK
            );
        }

        DrawRectangle(
            850,
            0,
            350,
            700,
            LIGHTGRAY
        );

        DrawText(
            "NODE DETAILS",
            900,
            30,
            25,
            BLACK
        );
        DrawText(
            "QUERY RESULT",
            900,
            350,
            25,
            BLACK
        );

        DrawText(
            queryResult.c_str(),
            900,
            400,
            20,
            BLACK
        );

        if(selectedNode!=-1)
        {
            Node* node =
                searchHash(
                    hashTable,
                    selectedNode
                );  

            if(node != NULL)
{
    DrawText(
      TextFormat(
      "ID : %d",
      node->id),
      900,
      100,
      20,
      BLACK
    );

    DrawText(
      TextFormat(
      "Type : %s",
      node->type),
      900,
      140,
      20,
      BLACK
    );
}

if(selectedNode==1)
{
    DrawText("Type : User",900,140,20,BLACK);
    DrawText("Name : Ali",900,180,20,BLACK);
    DrawText("Age : 22",900,220,20,BLACK);
    DrawText("City : Bursa",900,260,20,BLACK);
}

if(selectedNode==5)
{
    DrawText("Type : User",900,140,20,BLACK);
    DrawText("Name : Zeynep",900,180,20,BLACK);
    DrawText("Age : 23",900,220,20,BLACK);
    DrawText("City : Bursa",900,260,20,BLACK);
}

if(selectedNode==101)
{
    DrawText("Type : Photo",900,140,20,BLACK);
    DrawText("Title : Tatil",900,180,20,BLACK);
}

if(selectedNode==102)
{
    DrawText("Type : Photo",900,140,20,BLACK);
    DrawText("Title : Mezuniyet",900,180,20,BLACK);
}

if(selectedNode==103)
{
    DrawText("Type : Photo",900,140,20,BLACK);
    DrawText("Title : Konser",900,180,20,BLACK);
}

if(selectedNode==104)
{
    DrawText("Type : Photo",900,140,20,BLACK);
    DrawText("Title : Dogum Gunu",900,180,20,BLACK);
}

if(selectedNode==201)
{
    DrawText("Type : Event",900,140,20,BLACK);
    DrawText("Name : Rock Konseri",900,180,20,BLACK);
}

if(selectedNode==202)
{
    DrawText("Type : Event",900,140,20,BLACK);
    DrawText("Name : Teknoloji Zirvesi",900,180,20,BLACK);
}

if(selectedNode==203)
{
    DrawText("Type : Event",900,140,20,BLACK);
    DrawText("Name : Kariyer Gunleri",900,180,20,BLACK);
}
        }
        EndDrawing();
    }

    CloseWindow();
}
