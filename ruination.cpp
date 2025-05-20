#include "camera.h"
#include "player.h"
#include "weapon.h"
#include "enemy.h"
#include "bullet.h"
#include "include.h"

bullet bullet_main;
player player_main;
camera camera_main;
enemy enemy_main;
weapon rev(4000, 6);
weapon rep(6000, 12);
weapon main_weapon;

int screen_size_x = 1920;
int screen_size_y = 1080;

void weapon_logic()
{

    if (IsKeyPressed(KEY_ONE) && main_weapon.current_weapon != main_weapon.revolver)
    {
        main_weapon = rev;
        main_weapon.current_weapon = main_weapon.revolver;
    }
    if (IsKeyPressed(KEY_TWO) && main_weapon.current_weapon != main_weapon.repeater)
    {
        main_weapon = rep;
        main_weapon.current_weapon = main_weapon.repeater;
    }
}
void bullet_logic()
{
    bullet_main.bullet_hitbox();

    for (auto& bullet : main_weapon.bullets)
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

    for (auto& bullet : main_weapon.bullets)
    {
        bullet.draw(player_main.player_object);
    }

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    player_main.draw();
    main_weapon.draw(player_main.player_object);
    enemy_main.draw();
    EndMode2D();
    EndDrawing();
}
void input()
{
    main_weapon.fire(main_weapon);
    main_weapon.reload();
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
