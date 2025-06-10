#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "bullet.h"

player player_main;
camera camera_main;
enemy enemy_main;
ammo ammo_main;


int screen_size_x = 800;
int screen_size_y = 800;

void ammo_logic()
{
    bool clips_collision = CheckCollisionRecs(player_main.get_rectangle(), ammo_main.get_clips_rectangle());
    bool ammo_collision = CheckCollisionRecs(player_main.get_rectangle(), ammo_main.get_ammo_rectangle());
    
    if (clips_collision && ammo_main.current_clips_state == ammo_main.dropped)
    {
        player_main.current_weapon->current_clips += 1;
        ammo_main.current_clips_state = ammo_main.picked_up;
    }
    
    if (ammo_collision && ammo_main.current_ammo_state == ammo_main.dropped)
    {
        player_main.current_weapon->bullet_amount += 6;
        ammo_main.current_ammo_state = ammo_main.picked_up;
    }
}
void bullet_logic()
{
    bool bullet_collision = false;

    for (auto& bullet : player_main.get_bullets())
    {
        bullet.update_position(screen_size_x, screen_size_y);
        bullet_collision = CheckCollisionRecs(bullet.get_rectangle(player_main.player_object), enemy_main.get_rectangle());
    }

    if (bullet_collision)
    {
        enemy_main.current_state = enemy_main.dead;
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
    ammo_main.draw_ammo();
    player_main.draw();
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input()
{
    Vector2 center_position = { 0, 0 };

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
        bullet_logic();
        ammo_logic();
        camera_logic();
        draw();
        input();
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
