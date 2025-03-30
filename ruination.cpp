// ruin.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "player.h"
#include "raylib.h"
#include "camera.h"
#include "game.h"

// class import names
game game_main;
player player_main;
camera camera_main;

// main func
int main()
{
    // creating the window using two arguments. change color in the cpp file
    InitWindow(800, 800, "ruin");
    // fps setting
    SetTargetFPS(60);
    //hides the cursor to make way for reticle
    HideCursor();
    //sets a mouse offset due to strange mouse positioning (NEEDS TO BE FIXED)
    SetMouseOffset(-400, -400);

    // window loop to keep it open until closed by user
    while (!WindowShouldClose())
    {
        //camera
        camera_main.camera_input();
        game_main.handle_input();
        //movement & updates
        game_main.update();
        // drawing/camera
        BeginDrawing();
        BeginMode2D(camera_main.player_camera);
        ClearBackground(BLACK);
        DrawLine(800, 0, 0, 800, WHITE);
        DrawLine(0, 0, 800, 800, WHITE);

        game_main.draw();
        EndMode2D();
        EndDrawing();
        
        
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
