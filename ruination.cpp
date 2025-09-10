#include "include.h"
#include "camera.h"
#include "player.h"
#include "enemy.h"
#include "weapon.h"
#include "ammo.h"
#include "timer.h"


//TODO: Make bullet collision more global to where if it hits any object, it deactivates and disappears.
//TODO: Look into making a component system.


internal void InitGame()
{

    init_player();
    init_enemy();
    init_weapon();
    init_ammo(player_main.player_object);
    init_cam(player_main.player_object);
}
internal void DrawGame()
{
    draw_player();
    draw_weapon(player_main.player_object);
    draw_ammo(player_main.player_object);
    draw_enemy();

    DrawLine(800, 0, 0, 800, WHITE);
    DrawLine(0, 0, 800, 800, WHITE);
}
internal void UpdateGame()
{

    update_player();
    update_enemy(player_main.player_object, 10);
    update_weapon({ 0, 0 }, player_main.player_object);
    update_ammo(weapon_main.weapon_reticle, player_main.player_object);
    update_cam();
}
internal void free_mem()
{
    free_player();
}

// main func
int main()
{
    InitGame();
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
        UpdateGame();

        /*drawing*/
        DrawGame();

        /*ending functions*/
        EndDrawing();
        EndMode2D();
    }
    CloseWindow();
    
    return 0;
}
