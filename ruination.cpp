#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"

#define global_variable static
#define local_persist static
#define internal static

//TODO: Make collision Rectangles into collision Circles.
//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

player player_main;
camera camera_main;
enemy enemy_main;
ammo ammo_main;
weapon weapon_main;
    

internal void draw()
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
    player_main.draw();
    enemy_main.draw();
    ammo_main.draw(enemy_main.enemy_object);
    EndMode2D();
    EndDrawing();
}
internal void input()
{
    local_persist Vector2 center_position = { 0, 0 };


    player_main.take_input(player_main.player_object);
    camera_main.take_input();

}
internal void update()
{
    for (auto& bullet : player_main.get_bullets())
    {
        bullet.update(screen_size_x, screen_size_y, player_main.player_object, enemy_main.get_rectangle());
        enemy_main.update(player_main.player_object, player_main.current_weapon->bullet_damage, bullet.get_rectangle(player_main.player_object), enemy_main.get_rectangle());
    }
    camera_main.update();
    ammo_main.update(player_main.get_rectangle(), ammo_main.get_rectangle({ 0, 0 }), player_main.current_weapon);
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
        update();
    }
    // tells the window to close when told
    CloseWindow();

    return 0;
}
