#include "camera.h"
#include "player.h"
#include "include.h"

player player_main;
weapon weapon_main;
camera camera_main;


std::vector<bullet> bullets;


void bullet_logic()
{
    for (auto& bullet : bullets)
    {
        bullet.update_position();
    }
}
void camera_logic()
{
    camera_main.update();
}
void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera_main.player_camera);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    player_main.draw();
    weapon_main.draw(player_main.player_object);

    for (auto& bullet : weapon_main.bullets)
    {
        bullet.draw(player_main.player_object);
    }
    EndMode2D();
    EndDrawing();
}
void input()
{
    player_main.take_input();
    camera_main.take_input();
}

// main func
int main()
{
    // creating the window using two arguments. change color in the cpp file
    InitWindow(1920, 1080, "ruin");
    // fps setting
    SetTargetFPS(60);
    //hides the cursor to make way for reticle
    HideCursor();
    //sets a mouse offset due to strange mouse positioning (NEEDS TO BE FIXED)
    SetMouseOffset(-400, -400);

    // window loop to keep it open until closed by user
    while (!WindowShouldClose())
    {
        camera_logic();
        input();
        bullet_logic();
        draw();
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
