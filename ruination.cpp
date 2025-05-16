#include "camera.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"
#include "include.h"

player player_main;
camera camera_main;
enemy enemy_main;
weapon rev(4000, 6);
weapon rep(6000, 12);
weapon weapon_main;

int screen_size_x = 1920;
int screen_size_y = 1080;

void weapon_logic(weapon curr_weapon)
{

    if (weapon_main.current_weapon == weapon_main.revolver)
    {
        rev.fire(rev);
    }
    else
    {
        rep.fire(rep);
    }
}
void bullet_logic()
{

    for (auto& bullet : rev.bullets)
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
    BeginMode2D(camera_main.player_camera);

    for (auto& bullet : rev.bullets)
    {
        bullet.draw(player_main.player_object);
    }

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    player_main.draw();
    rev.draw(player_main.player_object);
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input()
{
    if (weapon_main.current_weapon == weapon_main.revolver)
    {
        rev.reload();
        rev.take_input();
    }
    else
    {
        rep.reload();
        rep.take_input();
    }
    player_main.take_input();
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
        
        input();
        weapon_logic();
        camera_logic();
        bullet_logic();
        draw();

    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
