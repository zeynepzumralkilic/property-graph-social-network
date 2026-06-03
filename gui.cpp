#include "raylib.h"
#include <string>

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

    VisualNode nodes[] =
    {
        {1,200,150,0},
        {2,400,150,0},
        {3,300,300,1},
        {4,500,300,2}
    };

    int selectedNode = -1;

    while(!WindowShouldClose())
    {
        Vector2 mouse = GetMousePosition();
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    // NODE SEÇME

    for(int i=0;i<4;i++)
    {
        if(CheckCollisionPointCircle(
            mouse,
            Vector2{nodes[i].x,nodes[i].y},
            30))
        {
            selectedNode = nodes[i].id;
        }
    }

    // BFS BUTONU

    if(CheckCollisionPointRec(
        mouse,
        Rectangle{20,20,120,40}))
    {
        queryResult =
        "BFS: 1 -> 2 -> 3 -> 4";
    }

    // DFS BUTONU

    if(CheckCollisionPointRec(
        mouse,
        Rectangle{160,20,120,40}))
    {
        queryResult =
        "DFS: 1 -> 3 -> 2 -> 4";
    }

    // SHORTEST PATH

    if(CheckCollisionPointRec(
        mouse,
        Rectangle{300,20,180,40}))
    {
        queryResult =
        "Shortest: 1 -> 2 -> 4";
    }

    // SOCIAL QUERY

    if(CheckCollisionPointRec(
        mouse,
        Rectangle{500,20,180,40}))
    {
        queryResult =
        "Friends:2 Events:4 Photos:3";
    }
}
       
        BeginDrawing();
    }


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

        DrawLine(200,150,400,150,BLACK);
        DrawLine(200,150,300,300,BLACK);
        DrawLine(400,150,500,300,BLACK);
        // FRIEND
DrawText(
    "FRIEND",
    280,
    120,
    18,
    GREEN
);

// LIKES
DrawText(
    "LIKES",
    220,
    210,
    18,
    BLUE
);

// ATTENDS
DrawText(
    "ATTENDS",
    430,
    210,
    18,
    ORANGE
);
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

        for(int i=0;i<4;i++)
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
            DrawText(
                TextFormat(
                "ID : %d",
                selectedNode),
                900,
                100,
                20,
                BLACK
            );

            if(selectedNode==1)
{
    DrawText("Type : User",900,140,20,BLACK);
    DrawText("Name : Ali",900,180,20,BLACK);
    DrawText("Age : 22",900,220,20,BLACK);
    DrawText("City : Bursa",900,260,20,BLACK);
}

if(selectedNode==2)
{
    DrawText("Type : User",900,140,20,BLACK);
    DrawText("Name : Veli",900,180,20,BLACK);
    DrawText("Age : 24",900,220,20,BLACK);
    DrawText("City : Istanbul",900,260,20,BLACK);
}

if(selectedNode==3)
{
    DrawText("Type : Photo",900,140,20,BLACK);
    DrawText("Title : Tatil",900,180,20,BLACK);
    DrawText("Owner : Ali",900,220,20,BLACK);
}

if(selectedNode==4)
{
    DrawText("Type : Event",900,140,20,BLACK);
    DrawText("Name : Konser",900,180,20,BLACK);
    DrawText("Location : Bursa",900,220,20,BLACK);
}

        EndDrawing();
    }

    CloseWindow();
}