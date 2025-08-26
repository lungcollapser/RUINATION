#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "bullet.h"
#include "timer.h"


//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

enemy enemy_main;
    
internal void draw_player()
{
    draw_p();
}
internal void update_player()
{
    update_p();
}
internal void draw_weapon(v2 player_object)
{
    draw_w(player_object);
}
internal void update_weapon()
{
    update_w({ 0, 0 }, player_main->player_object);
}
internal void draw_bullet(v2 player_object)
{
    draw_b(player_object);
}
internal void update_bullet(v2 player_object)
{

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && weapon_main->bullet_amount > 0)
    {

        shoot_b(weapon_main->weapon_reticle, player_object, 1);

        std::cout << "fired";
    }
}
internal void update_camera()
{
    update_cam();
}
internal void draw()
{

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    enemy_main.draw();
}
internal void init_mem()
{
    init_p();
    init_w();
}
internal void free_mem()
{
    free_p();
    free_w();
}

// main func
int main()
{
    InitWindow(screen_size_x, screen_size_y, "ruin");
    init_mem();
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);

    while (!WindowShouldClose())
    {
        /*starting functions*/
        BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(10, 10);

        /*drawing*/
        draw();
        draw_player();
        draw_weapon(player_main->player_object);
        draw_bullet(player_main->player_object);

        /*updates*/
        update_player();
        update_weapon();
        update_camera();
        update_bullet(player_main->player_object);
        update_b(weapon_main->weapon_reticle, player_main->player_object, 1);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
