#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"

player player_main;
camera camera_main;
enemy enemy_main;
ammo ammo_main;


int screen_size_x = 800;
int screen_size_y = 800;

Vector2 center_position = { 0, 0 };

void ammo_logic()
{
    bool player_collision = CheckCollisionRecs(player_main.get_rectangle(), ammo_main.get_clips_rectangle());
    
    if (player_collision)
    {
        player_main.current_weapon->current_clips += 1;
        std::cout << "clipped";

    }
}
void bullet_logic()
{

    for (auto& bullet : player_main.get_bullets())
    {
        bullet.update_position();
    }
}
void camera_logic()
{
    camera_main.update();
    camera_main.player_camera.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };
}

void draw()
{

    BeginDrawing();
    ClearBackground(BLACK);
    DrawFPS(10, 10);
    BeginMode2D(camera_main.player_camera);

    for (auto& bullet : player_main.get_bullets())
    {
        bullet.draw(player_main.player_object);
    }

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    ammo_main.draw_clips();
    player_main.draw();
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input()
{
    player_main.take_input(center_position);
    camera_main.take_input();

}

// main func
int main()
{

    // creating the window using two arguments. change color in the cpp file
    InitWindow(screen_size_x, screen_size_y, "ruin");
    // fps setting
    SetTargetFPS(60);
    //hides the cursor to make way for reticle
    HideCursor();
    //sets a mouse offset due to strange mouse positioning (NEEDS TO BE FIXED)
    SetMouseOffset(-400, -400);
    // window loop to keep it open until closed by user

    while (!WindowShouldClose())
    {
        draw();
        input();
        bullet_logic();
        ammo_logic();
        camera_logic();
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
