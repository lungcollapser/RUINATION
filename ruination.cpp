#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"


//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.

enemy enemy_main;

internal void InitGame(player player)
{
    init_player();
    init_weapon();
    init_ammo(player.player_object);
    init_cam(player.player_object);
}
internal void DrawGame(player player)
{
    draw_player();
    draw_weapon(player.player_object);
    draw_ammo(player.player_object);
    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
    enemy_main.draw();
}
internal void UpdateGame(weapon weapon, player player)
{
    update_player();
    update_weapon({ 0, 0 }, player.player_object);
    update_ammo(weapon.weapon_reticle, player.player_object);
    update_cam();
}
internal void free_mem()
{
    free_player();
}

// main func
int main()
{
    InitGame(player_main);
    InitWindow(screen_size_x, screen_size_y, "ruin");
    SetTargetFPS(120);
    HideCursor();
    SetMouseOffset(-400, -400);



    while (!WindowShouldClose())
    {
        /*starting functions*/
        BeginDrawing();
        BeginMode2D(camera_main.camera);
        ClearBackground(BLACK);
        DrawFPS(-300 + player_main.player_object.x, -300 + player_main.player_object.y);

        /*updates*/
        UpdateGame(weapon_main, player_main);

        /*drawing*/
        DrawGame(player_main);

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
