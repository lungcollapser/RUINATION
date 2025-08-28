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
internal void draw_weapon(player player)
{

    draw_w(player.player_object);
}
internal void update_weapon()
{
    update_w({ 0, 0 }, player_main.player_object);
}
internal void draw_bullet(player player)
{
    draw_b(player.player_object);
}
internal void update_bullet(weapon weapon, player player)
{
    update_b(weapon.weapon_reticle, player.player_object);
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
internal void init_mem(player player)
{
    init_p();
    init_w();
    init_b(player.player_object);
    init_cam(player.player_object);
}
internal void free_mem()
{
    free_p();
}

// main func
int main()
{
    InitWindow(screen_size_x, screen_size_y, "ruin");
    init_mem(player_main);
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);



    while (!WindowShouldClose())
    {
        /*starting functions*/
        BeginDrawing();
        BeginMode2D(camera_main.camera);
        ClearBackground(BLACK);
        DrawFPS(10, 10);


        update_player();
        update_weapon();
        update_camera();
        update_bullet(weapon_main, player_main);

        /*drawing*/
        draw();
        draw_player();
        draw_weapon(player_main);
        draw_bullet(player_main);

        /*updates*/

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
