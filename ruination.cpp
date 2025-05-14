#include "camera.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"
#include "include.h"

player player_main;
camera camera_main;
enemy enemy_main;
weapon weapon_main;
weapon weapon_revolver(4000, 6);
weapon weapon_repeater(6000, 12);



int screen_size_x = 1920;
int screen_size_y = 1080;


void weapon_logic(weapon curr_weapon)
{
    curr_weapon.fire();
}
void bullet_logic(weapon curr_weapon)
{

    for (auto& bullet : curr_weapon.bullets)
    {
        bullet.update_position();
    }
}
void camera_logic()
{
    camera_main.update();
    camera_main.player_camera.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };
}

void draw(weapon curr_weapon)
{

    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode2D(camera_main.player_camera);

    for (auto& bullet : curr_weapon.bullets)
    {
        bullet.draw(player_main.player_object);
    }

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    player_main.draw();
    curr_weapon.draw(player_main.player_object);
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input(weapon curr_weapon)
{
    curr_weapon.reload();
    curr_weapon.take_input();
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
        input(weapon_main.current_weapon);
        weapon_logic();
        camera_logic();
        bullet_logic();
        draw();

    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
